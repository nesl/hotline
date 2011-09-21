#include "deployment.h"
#include "misc_params.h"

#include "consensus.h"

#include "step.h"

module EstimatorP {
    provides interface EdgeWeight;

    uses interface Boot;
    uses interface SplitControl as RadioControl;
    uses interface Read<uint16_t>;
    uses interface Timer<TMilli> as WaitTimer;
    uses interface Random;

    uses interface SharedMemory;
    uses interface Sync;
    uses interface NeighborTable;
}
implementation {

#define MAX_ITERATIONS      300
#define UNSYNC_WAIT_PERIOD  307
#define M                   NUM_ACTUATORS

    enum {
        ST_IDLE = 0,
        ST_UPDATE,
        ST_CONSENSUS,
    } st;

    uint16_t sdata;
    uint8_t done;
    uint16_t curr_iter;
    float Wj;
    
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
        st = ST_UPDATE;
        post do_update();
    }

    void start_consensus() {
        //curr_iter++;
        st = ST_CONSENSUS;
        post do_consensus();
    }

    task void do_update() {
        if ( isSensor() ) {
            // Calculate new estimates at sensor.
            float g[M];
            uint8_t key;
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
        }
        call Sync.sync();
    }

    task void do_consensus() {
        if ( !isSensor() ) {
            // Actuator code.
            uint8_t key = (uint8_t)(TOS_NODE_ID-NUM_SENSORS);
            float i = 0;
            // Weightd avg has already been taken. Just reflect it as new
            // estimate.
            call SharedMemory.get(key, &i);
            dbg("EstimatorPEval", "ESTIMATE_%s_%u_%u_%f\n",
                    sim_time_string(),
                    key,            // Actuator # 
                    curr_iter,   // Combined iteration #
                    project(i));        // New estimate
            call SharedMemory.put(key, i);
        }
        call Sync.sync();
    }

    command float EdgeWeight.get(uint8_t key, am_addr_t n) {
        if ( n == TOS_NODE_ID ) return 0.0;
        return Wj;
    }

    event void Boot.booted() {
        done = 0;
        curr_iter = 0;
        Wj = 0.0;
        st = ST_IDLE;
        call RadioControl.start();
    }

    event void RadioControl.startDone(error_t result) {
        call SharedMemory.init();
        call Sync.init();
        // Wait for 240sec for neighbor discovery
        call WaitTimer.startOneShot(240*1024L);
    }

    event void WaitTimer.fired() {
        // Neighbor discovery has finished.
        if ( isSensor() ) {
            // Read sensor measurement
            if ( call Read.read() != SUCCESS ) {
                // Failed. Try again after some time.
                call WaitTimer.startOneShot(128L);
            }
        } else {
            // Actuator code.
            Wj = 1.0 / (float)call NeighborTable.size();
            start_update();
        }
    }

    event void Read.readDone(error_t result, uint16_t val) {
        // Sensor only.
        // This is the first reading. Ambient light.
        if ( result != SUCCESS ) {
            // Failed. Try again after some time.
            call WaitTimer.startOneShot(128L);
            return;
        }
        sdata = val;
        Wj = 1;
        start_update();
    }

    event void Sync.synced() {
        if ( st == ST_CONSENSUS ) {
            // Node just synced after consensus negotiation.
            if ( curr_iter >= MAX_ITERATIONS ) {
                // Stop the simulation.
                done = 1;
                dbg("EstimatorPEval", "##_%s_%u_Stopping\n",
                        sim_time_string(),
                        curr_iter);
            } else {
                start_update();
            }
        } else if ( st == ST_UPDATE ) {
            // Node just synced after subgradient update.
            start_consensus();
        }
    }

    event void SharedMemory.changed(uint8_t key) {}

    event void NeighborTable.neighborAdded(int8_t idx) {}
    event void NeighborTable.neighborRemoved(int8_t idx) {}

    event void RadioControl.stopDone(error_t result) {}
    
}

