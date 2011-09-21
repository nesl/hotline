#include <locks.h>
#include <zone_intset.h>

#include "step.h"
#include "deployment.h"
#include "zonedep.h"

#include "priority.h"

module EstimatorStaticP {
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

    enum {
        ST_IDLE = 0,
        ST_ITERATING,
        ST_WAITING,
    } st;

    uint32_t pr;
    uint16_t sdata;
    uint8_t done;
    uint16_t curr_iter;
    uint8_t timer_fired;
    uint16_t finish_iter;
    
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
        if ( st != ST_IDLE ) return;
        st = ST_ITERATING;
        curr_iter++;
        dbg("EstimatorStaticPEval", "APP_%s_ACQUIRE_%lu_%u\n", 
            sim_time_string(), pr, curr_iter);
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
                    dbg("EstimatorStaticP", "##_%s_%u_shared error\n",
                            sim_time_string(),
                            key);        // Actuator # 
                }
            }
        }
        dbg("EstimatorStaticPEval", "APP_%s_RELEASE\n", sim_time_string());
        call VirtualLock.releaseLock();
        st = ST_WAITING;
        call Sync.sync();
    }

    command void DebugLog.print(uint16_t iter_num) {
        uint8_t key;
        for ( key=0; key<M; key++ ) {
            if ( A_i(key) != 0 ) {
                float i = 0;
                call SharedMemory.get(key, &i);
                dbg("EstimatorStaticPEval", "ESTIMATE_%s_%u_%u_%f\n",
                        sim_time_string(),
                        key,        // Actuator # 
                        iter_num,   // Iteration number
                        i);         // New estimate
            }
        }
    }

    event void Boot.booted() {
        curr_iter = 0;
        pr = 0;
        st = ST_IDLE;
        timer_fired = 0;
        // Variables for determining end of simulation
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
            //call WaitTimer.startOneShot(240*1024L);
            call WaitTimer.startOneShot(240*1024L+(call Random.rand32()%128));
        }
    }

    event void WaitTimer.fired() {
        // This will only happen for sensor nodes.
        if ( timer_fired == 0 ) {
            // Neighbor discovery has finished.
            sdata = call UserIntensity.get();
#ifdef RING_PR
            pr = get_priority(TOS_NODE_ID);
#else
            pr = TOS_NODE_ID;
#endif
            call VirtualLock.setPriority(pr);
            timer_fired++;
            // Wait 240sec for priority dissemination
            call WaitTimer.startOneShot(240*1024L);
        } else {
            start_iteration();
        }
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
            dbg("EstimatorStaticPEval", "SENSOR_%s_%lu_%u\n",
                sim_time_string(), mean, ev);
#ifdef ADAPTIVE
            if ( ev ) {
                // Sensor readings have changed significantly
                // Start iterations. 
                call Iterations.start();
                dbg("EstimatorStaticP", "##_%s_%u_Reset\n",
                        sim_time_string(),
                        curr_iter);
            } 
            if ( st == ST_IDLE ) {
                if ( !ev ) {
                    // Slow down the iterations.
                    call Iterations.stop();
                    dbg("EstimatorStaticP", "##_%s_%u_Slowing\n",
                            sim_time_string(),
                            curr_iter);
                }
            }
#endif
            if ( st == ST_IDLE ) {
                // Synchronized iterations with other nodes. Start
                // another iteration.
                start_iteration();
            }
            // Restart the sensing timer.
            call SenseTimer.stop();
            call SenseTimer.startOneShot(256L);
        } else {
            // Some failure in reading sensor. Try again.
            if ( !call SenseTimer.isRunning() ) {
                call SenseTimer.startOneShot(128L);
            }
        }
    }

    event void SenseTimer.fired() {
        if ( call Read.read() != SUCCESS ) {
            call SenseTimer.startOneShot(128L);
        }
    }

    event void VirtualLock.lockGranted(int8_t err) {
        if ( err == LOCK_GRANT_NORMAL ) {
            dbg("EstimatorStaticPEval", "APP_%s_GRANTED_%lu\n",
                sim_time_string(), pr);
            post do_iterate();
        }
    }

    event void Sync.synced() {
        st = ST_IDLE;
        finish_iter++;
        dbg("EstimatorStaticPEval", "APP_%s_SYNCED_%u\n", 
                sim_time_string(), curr_iter);
        // Check sensor to decide whether to start next iteration
        call Read.read();
    }

    event void UserIntensity.changed(uint16_t value) {
        dbg("EstimatorStaticPEval", "APP_%s_USEREVENT_%u_%u\n", 
                sim_time_string(), curr_iter, value);
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

