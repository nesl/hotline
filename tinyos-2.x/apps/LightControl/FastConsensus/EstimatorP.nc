#include <zone_intset.h>

#include "deployment.h"
#include "misc_params.h"
#include "zonedep.h"

#include "consensus.h"

#include "step.h"

module EstimatorP {
    provides interface DebugLog;

    uses interface Boot;
    uses interface SplitControl as RadioControl;
    uses interface Read<uint16_t>;
    uses interface Stats as RawStats;
    uses interface Timer<TMilli> as WaitTimer;
    uses interface Timer<TMilli> as SenseTimer;
    uses interface UserIntensity;
    uses interface Random;

    uses interface SharedMemory;
    uses interface Sync;
    uses interface Zone;
}
implementation {

#define PSI                 1
        
#ifndef MAX_ITERATIONS
#define MAX_ITERATIONS      (PSI*100)
#endif

#define UNSYNC_WAIT_PERIOD  307
#define M                   NUM_ACTUATORS

    uint16_t sdata;
    uint8_t done;
    int8_t psi;
    uint16_t curr_iter, finish_iter;
    
    task void do_update();
    task void do_consensus();

    bool isSensor() {
        return (TOS_NODE_ID < NUM_SENSORS);
    }

    float project(float v) {
        if ( v < 0 ) {
            v = 0;
        } else if ( v > I_MAX ) {
            v = I_MAX;
        }
        return v;
    }

    float calculate_Li(uint16_t val) {
        float Li = (float)ambient();
        uint8_t j;
        for ( j=0; j<M; j++ ) {
            float i = 0;
            if ( A_i(j) == 0 ) continue;
            call SharedMemory.get(j, &i);
            Li += ( A_i(j) * i );
        }
        Li -= (float)val;
        return Li;
    }

    void calculate_gradient(uint16_t val, float *g) {
        uint8_t j;
        float Li = calculate_Li(val);
        for ( j=0; j<M; j++ ) {
            g[j] = A_i(j) * Li;
        }
    }

    void start_update() {
        curr_iter++;
        dbg("EstimatorPEval", "APP_%s_ACQUIRE_%u_%lu\n",
                sim_time_string(), 128, curr_iter);
        post do_update();
    }

    void start_consensus() {
        // This is never called in FC. So ignore it. 
        curr_iter++;
        dbg("EstimatorPEval", "APP_%s_ACQUIRE_%u_%lu\n",
                sim_time_string(), 128, curr_iter);
        post do_consensus();
    }

    task void do_update() {
        // Calculate new estimates
        float g[M];
        uint8_t key;
        dbg("EstimatorPEval", "APP_%s_GRANTED_%u\n",
                sim_time_string(),
                curr_iter);  // Combined iteration #
        // A reading taken during a iteration
        calculate_gradient(sdata, g);
        for ( key=0; key<M; key++ ) {
            float i = 0;
            // Ignore actuators that do not matter
            if ( A_i(key) == 0 ) continue;
            call SharedMemory.get(key, &i);
            i = project(i) - (STEP_SIZE*g[key]);
            call SharedMemory.put(key, i);
            dbg("EstimatorP", "##_%s_%u_%u_%f_subiterate\n",
                    sim_time_string(),
                    key,            // Actuator # 
                    curr_iter,   // Combined iteration #
                    i);        // New estimate
        }
        psi = PSI-1;
        dbg("EstimatorPEval", "APP_%s_RELEASE\n",
                sim_time_string());
        call Sync.sync();
    }

    task void do_consensus() {
        // This is never called in FC. So ignore it. 
        uint8_t key;
        dbg("EstimatorPEval", "APP_%s_GRANTED_%u\n",
                sim_time_string(),
                curr_iter);  // Combined iteration #
        psi--;
        for ( key=0; key<M; key++ ) {
            float i = 0;
            // Ignore actuators that do not matter
            if ( A_i(key) == 0 ) continue;
            // Consensus average has already been done in the cache sync
            // module. Just reflect the new value as this node's current value.
            call SharedMemory.get(key, &i);
            call SharedMemory.put(key, i);
            dbg("EstimatorP", "##_%s_%u_%u_%f_consensus\n",
                    sim_time_string(),
                    key,            // Actuator # 
                    curr_iter,   // Combined iteration #
                    i);             // New estimate
        }
        dbg("EstimatorPEval", "APP_%s_RELEASE\n",
                sim_time_string());
        call Sync.sync();
    }

    command void DebugLog.print(uint16_t iter_num) {
        if ( psi <= 0 ) {
            uint8_t key;
            for ( key=0; key<M; key++ ) {
                if ( A_i(key) != 0 ) {
                    float i = 0;
                    call SharedMemory.get(key, &i);
                    dbg("EstimatorPEval", "ESTIMATE_%s_%u_%u_%f\n",
                            sim_time_string(),
                            key,            // Actuator # 
                            iter_num,       // Iteration number
                            project(i));    // New estimate
                }
            }
        }
    }

    event void Boot.booted() {
        done = 0;
        curr_iter = 0;
        psi = 0;
        finish_iter = 0;
        call RadioControl.start();
    }

    event void RadioControl.startDone(error_t result) {
        zone_intset_t z;
        set_zone(&z);
        call UserIntensity.init();
        call SharedMemory.init();
        call Sync.init();
        call RawStats.init();
        call Zone.set((uint8_t*)&z);
        if ( isSensor() ) {
            // Wait for 240sec for neighbor discovery
            call WaitTimer.startOneShot(240*1024L);
        }
    }

    event void WaitTimer.fired() {
        // This will only happen for sensor nodes.
        // Read sensor measurement
        sdata = call UserIntensity.get();
        start_update();
    }

    event void SenseTimer.fired() {
        if ( call Read.read() != SUCCESS ) {
            call SenseTimer.startOneShot(128L);
        }
    }

    event void Read.readDone(error_t result, uint16_t val) {
        if ( result == SUCCESS ) {
            uint16_t mean;
            call RawStats.add(val);
            mean = call RawStats.getMean();
            dbg("EstimatorPEval", "SENSOR_%s_%lu_%u\n",
                sim_time_string(), mean, 1);
        } else {
            call SenseTimer.startOneShot(128L);
        }
        // Start another subgradient update or consensus negotiation
        if ( psi <= 0 ) {
            start_update();
        } else {
            // This is never called in FC. So ignore it. 
            start_consensus();
        }
    }

    event void Sync.synced() {
        dbg("EstimatorPEval", "APP_%s_SYNCED_%u\n", 
                sim_time_string(), curr_iter);
        if ( curr_iter >= MAX_ITERATIONS ) {
            // Stop the simulation.
            done = 1;
            dbg("EstimatorP", "##_%s_%u_Stopping\n",
                    sim_time_string(),
                    curr_iter);
        } else {
            if ( call Read.read() != SUCCESS ) {
                call SenseTimer.startOneShot(128L);
            }
        }
    }

    event void UserIntensity.changed(uint16_t value) {
        dbg("EstimatorPEval", "APP_%s_USEREVENT_%u_%u\n", 
                sim_time_string(), curr_iter, value);
    }

    event void SharedMemory.changed(uint8_t key) {}
    event void RadioControl.stopDone(error_t result) {}
    event bool Zone.changed(dip_key_t key) { return TRUE; }

}

