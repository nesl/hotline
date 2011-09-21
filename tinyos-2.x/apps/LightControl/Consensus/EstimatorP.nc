#include "deployment.h"
#include "misc_params.h"

#include "consensus.h"

#include "step.h"

module EstimatorP {
    uses interface Boot;
    uses interface SplitControl as RadioControl;
    uses interface Read<uint16_t>;
    uses interface Timer<TMilli> as WaitTimer;
    uses interface Random;

    uses interface SharedMemory;
    uses interface Sync;
}
implementation {

#define PSI                 1
#define MAX_ITERATIONS      (PSI*600)
#define UNSYNC_WAIT_PERIOD  307
#define M                   NUM_ACTUATORS

    uint16_t sdata;
    uint8_t done;
    int8_t psi;
    uint32_t curr_iter;
    
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
        post do_update();
    }

    void start_consensus() {
        curr_iter++;
        post do_consensus();
    }

    task void do_update() {
        // Calculate new estimates
        float g[M];
        uint8_t key;
        // A reading taken during a iteration
        calculate_gradient(sdata, g);
        for ( key=0; key<M; key++ ) {
            float i;
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
        call Sync.sync();
    }

    task void do_consensus() {
        uint8_t key;
        psi--;
        for ( key=0; key<M; key++ ) {
            float i;
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
        call Sync.sync();
    }

    event void Boot.booted() {
        done = 0;
        curr_iter = 0;
        psi = 0;
        call RadioControl.start();
    }

    event void RadioControl.startDone(error_t result) {
        call SharedMemory.init();
        call Sync.init();
        if ( isSensor() ) {
            // Wait for 240sec for neighbor discovery
            call WaitTimer.startOneShot(240*1024L);
        }
    }

    event void WaitTimer.fired() {
        // This will only happen for sensor nodes.
        // Read sensor measurement
        if ( call Read.read() != SUCCESS ) {
            // Failed. Try again after some time.
            call WaitTimer.startOneShot(128L);
        }
    }

    event void Read.readDone(error_t result, uint16_t val) {
        // This is the first reading. Ambient light.
        if ( result != SUCCESS ) {
            // Failed. Try again after some time.
            call WaitTimer.startOneShot(128L);
            return;
        }
        sdata = val;
        start_update();
    }

    event void Sync.synced() {
        if ( psi <= 0 ) {
            // Consensus iterations finished. Project the estimates.
            uint8_t key;
            for ( key=0; key<M; key++ ) {
                float i;
                if ( A_i(key) == 0 ) continue;
                call SharedMemory.get(key, &i);
                dbg("EstimatorPEval", "ESTIMATE_%s_%u_%u_%f\n",
                        sim_time_string(),
                        key,            // Actuator # 
                        curr_iter,   // Combined iteration #
                        project(i));        // New estimate
            }
        } 
        if ( curr_iter >= MAX_ITERATIONS ) {
            // Stop the simulation.
            done = 1;
            dbg("EstimatorPEval", "##_%s_%u_Stopping\n",
                    sim_time_string(),
                    curr_iter);
        } else {
            // Start another subgradient update or consensus negotiation
            if ( psi <= 0 ) {
                start_update();
            } else {
                start_consensus();
            }
        }
    }

    event void SharedMemory.changed(uint8_t key) {}

    event void RadioControl.stopDone(error_t result) {}
    
}

