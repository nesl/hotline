
#include "deployment.h"
#include "misc_params.h"

#include "step.h"

module EstimatorP {
    uses interface Boot;
    uses interface SplitControl as RingControl;
    uses interface UserIntensity;
    uses interface Timer<TMilli> as StampTimer;
    uses interface Random;
    uses interface Ring;
}
implementation {

#ifdef USE_BROADCAST
#define MAX_ITERATIONS      100
#else
#define MAX_ITERATIONS      100
#endif

#define M               NUM_ACTUATORS

    float i[M];
    uint16_t sdata;
    uint8_t done;
    uint16_t curr_version;
    uint16_t finish_iter;
    
    task void do_iterate();

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
            Li += ( A_i(j) * i[j] );
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

    task void do_iterate() {
        // Calculate new estimates
        float g[M];
        uint8_t key;
        // A reading taken during a iteration
        calculate_gradient(sdata, g);
        for ( key=0; key<M; key++ ) {
            i[key] = project(i[key] - (STEP_SIZE*g[key]));
            if ( TOS_NODE_ID == 0 ) {
                dbg("EstimatorPEval", "ESTIMATE_%s_%u_%u_%f\n",
                        sim_time_string(),
                        key,            // Actuator # 
                        curr_version,   // Combined iteration #
                        i[key]);        // New estimate
            }
        }
        if ( curr_version <= MAX_ITERATIONS ) {
            // Send the token to the next neighbor for estimation
            call Ring.sendToNext(curr_version, i, sizeof(i));
            //dbg("EstimatorPEval", "##_%s_%u_sending token\n",
            dbg("EstimatorPEval", "APP_%s_RELEASE\n",
                    sim_time_string());
            if ( curr_version == MAX_ITERATIONS ) {
                // No more iterations to do
                done = 1;
            } else {
                dbg("EstimatorPEval", "APP_%s_ACQUIRE_%u_%lu\n",
                        sim_time_string(), 128, curr_version+1);
            }
        } 
    }

    event void Boot.booted() {
        memset(i, 0, sizeof(i));
        curr_version = 0;
        // Variables for determining end of simulation
        done = 0;
        finish_iter = 0;
        call RingControl.start();
    }

    event void RingControl.startDone(error_t result) {
        if ( isSensor() ) {
            call UserIntensity.init();
            sdata = call UserIntensity.get();
            dbg("EstimatorPEval", "APP_%s_ACQUIRE_%u_%lu\n",
                    sim_time_string(), 128, curr_version+1);
            if ( TOS_NODE_ID == 0 ) {
                // Wait for 60sec to let all nodes start up
                call StampTimer.startOneShot(60*1024L);
            }
        }
    }

    event void StampTimer.fired() {
        // Node 0 starts the iterations
        curr_version++;
        dbg("EstimatorPEval", "APP_%s_GRANTED_%u\n",
                sim_time_string(),
                curr_version);  // Combined iteration #
        post do_iterate();
    }

    event void Ring.receive(uint16_t token, void *payload, uint16_t len) {
        if ( TOS_NODE_ID == 0 ) {
            if ( token < curr_version ) return; // duplicate
            curr_version++;
            if ( len != sizeof(i) ) {
                dbg("EstimatorP", "##_%s_%u_error\n",
                        sim_time_string(),
                        curr_version);   // Combined iteration #
                return;
            }
            dbg("EstimatorPEval", "APP_%s_GRANTED_%u\n",
                    sim_time_string(),
                    curr_version);  // Combined iteration #
            memcpy(i, payload, len);
            post do_iterate();
            return;
        }
        // Any other node.
        if ( token > curr_version ) {
            // New token. Update current version.
            curr_version = token;
            if ( len != sizeof(i) ) {
                dbg("EstimatorP", "##_%s_%u_error\n",
                        sim_time_string(),
                        curr_version);   // Combined iteration #
                return;
            }
            dbg("EstimatorPEval", "APP_%s_GRANTED_%u\n",
                    sim_time_string(),
                    curr_version);  // Combined iteration #
            memcpy(i, payload, len);
            post do_iterate();
        }
    }

    event void Ring.sendDone(uint16_t token, error_t err) {
        dbg("EstimatorP", "##_%s_%u_token sent\n",
                sim_time_string(),
                token);   // Combined iteration #
    }

    event void UserIntensity.changed(uint16_t val) {
        sdata = val;
    }

    event void RingControl.stopDone(error_t result) {}
    
}

