#include <locks.h>
#include <zone_intset.h>

#include "step.h"
#include "deployment.h"
#include "zonedep.h"

#include "priority.h"

module EstimatorDynamicP {
    provides interface DebugLog;

    uses interface Boot;
    uses interface SplitControl as RadioControl;
    uses interface Timer<TMilli> as WaitTimer;
    uses interface Timer<TMilli> as SenseTimer;
    uses interface Random;

    uses interface UserIntensity;

    uses interface Read<uint16_t>;
    uses interface Stats as RawStats;
    uses interface Stats as MeanStats;

    uses interface SharedMemory;
    uses interface Sync;
    uses interface StdControl as Iterations;
    uses interface VirtualLock;
    uses interface Zone;
}
implementation {

#ifdef ADAPTIVE
#ifndef SIM_EVENTS          
// This option is used for message cost post-stability
#define MAX_ITERATIONS      200
#endif
#endif

#ifndef MAX_ITERATIONS
#define MAX_ITERATIONS      100
#endif

#define M                   NUM_ACTUATORS
#define FACTOR              1   // (in %)

    uint32_t pr;
    uint16_t sdata;
    uint8_t done;
    uint16_t curr_iter, last_iter;
    bool started;
    uint8_t stop_count;
    uint16_t finish_iter;
    
    enum {
        ITERATING   = 0,
        NOT_ITERATING,
    } st;

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
        float i;
        uint8_t j;
        for ( j=0; j<M; j++ ) {
            i = 0;
            call SharedMemory.get(j, &i);
            Li += ( A_i(j) * i );
        }
        if ( val > ambient() ) {
            Li -= (float)val;
        } else {
            Li -= (float)ambient();
        }
        return Li;
    }

    void calculate_gradient(uint16_t val, float *g) {
        uint8_t j;
        float Li = calculate_Li(val);
        for ( j=0; j<M; j++ ) {
            g[j] = A_i(j) * Li;
        }
    }

    void start_iteration() {
        if ( started ) return;
        started = TRUE;
        curr_iter++;
#ifdef RING_PR
        // Strict Ring order
        pr = get_priority(TOS_NODE_ID);
#elif defined TIMESTAMPS
        // FCFS - undefined order
        pr = call WaitTimer.getNow();
#else
        // Strict order
        pr = TOS_NODE_ID;
#endif
        dbg("EstimatorDynamicPEval", "APP_%s_ACQUIRE_%lu_%u\n", 
            sim_time_string(), pr, curr_iter);
        call VirtualLock.setPriority(pr);
        call VirtualLock.acquireLock(128);
    }

    task void do_iterate() {
        // Calculate new estimates
        float g[M];
        uint8_t key;
        // A reading taken during a iteration
        calculate_gradient(sdata, g);
        // Update the latest version number of estimates
        for ( key=0; key<M; key++ ) {
            if ( A_i(key) != 0 ) {
                float i = 0;
                call SharedMemory.get(key, &i);
                i = project(i - (STEP_SIZE*g[key]));
                if ( call SharedMemory.put(key, i) != SUCCESS ) {
                    dbg("EstimatorDynamicP", "##_%s_%u_shared error\n",
                            sim_time_string(),
                            key);        // Actuator # 
                }
                //dbg("EstimatorDynamicPEval", "ESTIMATE_%s_%u_%u_%f\n",
                //        sim_time_string(),
                //        key,        // Actuator # 
                //        curr_iter,  // Iteration number
                //        i);    // New estimate
            }
        }
        dbg("EstimatorDynamicPEval", "APP_%s_RELEASE\n", sim_time_string());
        call VirtualLock.releaseLock();
        started = FALSE;
        call Sync.sync();
    }

    command void DebugLog.print(uint16_t iter_num) {
        uint8_t key;
        for ( key=0; key<M; key++ ) {
            if ( A_i(key) != 0 ) {
                float i = 0;
                uint16_t ptr = last_iter + 1;
                call SharedMemory.get(key, &i);
                for ( ; ptr<=iter_num; ptr++ ) {
                    dbg("EstimatorDynamicPEval", "ESTIMATE_%s_%u_%u_%f\n",
                            sim_time_string(),
                            key,        // Actuator # 
                            ptr,        // Iteration number
                            i);         // New estimate
                }
            }
        }
        // Update the last iteration count printed.
        last_iter = iter_num;
    }

    event void Boot.booted() {
        curr_iter = 0;
        last_iter = 0;
        pr = 0;
        started = FALSE;
        st = ITERATING;
        // Variables for determining end of simulation
        stop_count = 0;
        done = 0;
        finish_iter = 0;
        call RadioControl.start();
    }

    event void RadioControl.startDone(error_t result) {
        zone_intset_t z;
        set_zone(&z);
        call UserIntensity.init();
        call SharedMemory.init();
        // Set zone, start neighbor discovery
        // Iterations are started by default.
        call Sync.init();
        call RawStats.init();
        call MeanStats.init();
        call Zone.set((uint8_t*)&z);
        if ( isSensor() ) {
            // Wait for 240sec for neighbor discovery
#ifdef TIMESTAMPS
            call WaitTimer.startOneShot(240*1024L+(call Random.rand32()%128));
#else
            call WaitTimer.startOneShot(240*1024L);
#endif
        }
#ifdef PHYLOCK_RELAX_ACCESS
        // Configure Vlock
        call VirtualLock.enableRandomAccess();
#endif
    }

    event void WaitTimer.fired() {
        // This will only happen for sensor nodes.
        // Neighbor discovery has finished.
        sdata = call UserIntensity.get();
        start_iteration();
    }

    bool outsideLimits(uint16_t mean) {
#ifndef SIM_EVENTS
        uint16_t threshold = (FACTOR * sdata)/100;
        return (abs((int32_t)mean-(int32_t)sdata)>(int32_t)threshold);
#else
        // When simulating events, only signal TRUE on user events
        uint16_t newval = call UserIntensity.get();
        if ( newval != sdata ) {
            // Some user event happened. Store new value.
            sdata = newval;
            return TRUE;
        }
        return FALSE;
#endif
    }

    event void Read.readDone(error_t result, uint16_t val) {
        if ( result == SUCCESS ) {
            bool ev = FALSE;
            uint16_t mean;
            call RawStats.add(val);
            mean = call RawStats.getMean();
            call MeanStats.add(mean);
            ev = call MeanStats.varianceHigh(2) || outsideLimits(mean);
            dbg("EstimatorDynamicPEval", "SENSOR_%s_%lu_%u\n",
                sim_time_string(), mean, ev);
#ifdef ADAPTIVE
            if ( ev ) {
                // Sensor readings have changed significantly
                if ( st == NOT_ITERATING ) {
                    // Start iterations.
                    st = ITERATING;
                    stop_count = 0;
                    call Iterations.start();
                    dbg("EstimatorDynamicPEval", "##_%s_%u_StartIter\n",
                            sim_time_string(),
                            curr_iter);
                }
                // Start a new iteration
                done = 0;
                start_iteration();
                dbg("EstimatorDynamicP", "##_%s_%u_StartingNew\n",
                        sim_time_string(),
                        curr_iter);
            } else {
                if ( st == ITERATING ) {
                    // Stop iterations.
                    call Iterations.stop();
                    st = NOT_ITERATING;
                    dbg("EstimatorDynamicPEval", "##_%s_%u_%u_StopIter\n",
                            sim_time_string(),
                            curr_iter,
                            stop_count);
                } else {
                    if ( !done ) {
                        if ( stop_count >= 40 ) {
                            dbg("EstimatorDynamicPEval", "##_%s_%u_%u_StoppingNoEvents\n",
                                    sim_time_string(),
                                    curr_iter,
                                    stop_count);
                            // This is only signalled when values have
                            // stabilized for quite some time.
                            done = 1;
                        } else {
                            stop_count++;
                        }
                    }
                }
                call SenseTimer.startOneShot(256L);
            }
#else
            start_iteration();
            dbg("EstimatorDynamicP", "##_%s_%u_StartingNew\n",
                    sim_time_string(),
                    curr_iter);
#endif
        } else {
            // Read failed. Retry after some time.
            call SenseTimer.startOneShot(128L);
        }
    }

    event void SenseTimer.fired() {
        if ( call Read.read() != SUCCESS ) {
            call SenseTimer.startOneShot(128L);
        }
    }

    event void VirtualLock.lockGranted(int8_t err) {
        if ( err == LOCK_GRANT_NORMAL ) {
            dbg("EstimatorDynamicPEval", "APP_%s_GRANTED_%lu\n",
                sim_time_string(), pr);
            post do_iterate();
        }
    }

    event void Sync.synced() {
        dbg("EstimatorDynamicPEval", "APP_%s_SYNCED_%u\n",
                sim_time_string(), curr_iter);
        finish_iter++;
        // Check sensor to decide whether to start next iteration
        call Read.read();
    }

    event void UserIntensity.changed(uint16_t value) {
        // If the node is iterating or not, it will automatically pick up this change
        // in readDone().
        dbg("EstimatorDynamicPEval", "APP_%s_USEREVENT_%u_%u\n", 
                sim_time_string(), curr_iter, value);
        done = 0;
    }

    event bool VirtualLock.checkNbrMetric(uint32_t metric) {
        if ( metric < pr ) return TRUE;
        if ( metric == pr ) {
            // 6.25% chance of violation with
            // this logic
            uint16_t r = call Random.rand16() % 100;
            if ( r < 25 ) return TRUE;
        }
        return FALSE;
    }

    event void SharedMemory.changed(uint8_t key) {}
    event void VirtualLock.lockRequest(uint32_t metric) {}
    event void VirtualLock.lockConflict() {}
    event void VirtualLock.lockViolation(uint32_t metric) {}
    event bool Zone.changed(dip_key_t key) { return TRUE; }
    event void RadioControl.stopDone(error_t result) {}

}

