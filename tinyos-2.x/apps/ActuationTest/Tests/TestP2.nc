
// This is a special case for comparing parallel operations.
// One iteration only, all nodes start at almost same time.
// Set static priorities through python script.

#include <Camera.h>
#include <locks.h>
#include <Timer.h>

module TestP2
{
    uses interface RawActControl<ptz_config_t> as CameraControl;
    uses interface PhysicalConfig<pose2d_t> as CameraConfig;
    uses interface VirtualLock;

    uses interface Random;

    uses interface SplitControl as RadioControl;
    uses interface Boot;

    uses interface Timer<TMilli> as TestTimer;
}
implementation
{
    int8_t op = 0;
    uint8_t state = 0;
    uint32_t selfmetric;
    uint32_t waittime, holdtime;
    uint16_t max_iterations;
    uint16_t curr_iterations = 0;
    uint8_t done = 0;

    task void dummyTask() {
        switch (op) {
            case 0:
                {
                    state = 1;
#ifdef TEST_dynamic
                    // Dynamic priority: FCFS
                    selfmetric = call TestTimer.getNow();
#endif
#ifdef TEST_static
                    // Static priority
                    selfmetric = TOS_NODE_ID;
#endif
                    dbg("TestP1", "App: Trying to acquire lock.\n");
                    dbg("TestP1Eval", "APP_%s_ACQUIRE_%u_%u\n", 
                            sim_time_string(), waittime, selfmetric);
                    curr_iterations++;
                    call VirtualLock.setPriority(selfmetric);
                    call VirtualLock.acquireLock(holdtime);
                    break;
                }
            case 2:
                {
                    call VirtualLock.releaseLock();
                    state = 0;
                    dbg("TestP1", "App: Lock released.\n");
                    dbg("TestP1Eval", "APP_%s_RELEASE\n", sim_time_string());
                    if ( curr_iterations < max_iterations ) {
#ifdef LOAD_L1
                        // Start another iteration after random time in [1, 3]
                        // seconds
                        uint32_t dtfire = (call Random.rand32() % (2*1024L)) +
                            (1*1024L);
#endif
#ifdef LOAD_L2
                        // Start another iteration after random time in [15, 25]
                        // seconds
                        uint32_t dtfire = (call Random.rand32() % (10*1024L)) +
                            (15*1024L);
#endif
#ifdef LOAD_L3
                        // Start another iteration after random time in [60,180]
                        // seconds
                        uint32_t dtfire = (call Random.rand32() % (120*1024L)) +
                            (60*1024L);
#endif
#ifdef LOAD_L4
                        // Start another iteration after random time in
                        // [300,600] seconds
                        uint32_t dtfire = (call Random.rand32() % (300*1024L)) +
                            (300*1024L);
#endif
                        op = 0;
                        call TestTimer.startOneShot(dtfire);
                    } else {
                        dbg("TestP1", "App: End of Work.\n");
                        done = 1;
                    }
                    break;
                }
            default: break;
        }
    }

    event void VirtualLock.lockGranted(int8_t err) {
        switch (err) {
            case LOCK_GRANT_NORMAL:
                {
                    dbg("TestP1", 
                            "App: Acquired lock.\n");
                    dbg("TestP1Eval", "APP_%s_GRANTED_%lu\n", 
                            sim_time_string(), selfmetric);
                    call TestTimer.startOneShot(128);
                    //call TestTimer.startOneShot(256);
                    op = 2;
                    state = 2;
                    break;
                }
            case LOCK_GRANT_HOLD_EXPIRED:
                {
                    dbg("TestP1",
                            "App: Lock hold time expired.\n");
                    dbg("TestP1Eval", "APP_%s_HOLDEXPIRED\n", sim_time_string());
                    // Release the lock or wait for work to finish
                    //call VirtualLock.releaseLock();
                    break;
                }
            default: break;
        }
    }

    event bool VirtualLock.checkNbrMetric(uint32_t metric) {
        if ( metric < selfmetric ) return TRUE;
        if ( metric == selfmetric ) {
            // 6.25% chance of violation with this logic
            uint16_t r = call Random.rand16() % 100;
            if ( r < 25 ) return TRUE;
        }
        return FALSE;
    }

    event void VirtualLock.lockRequest(uint32_t metric) {
        switch (state) {
            case 0:
                {
                    dbg("TestP1", 
                        "App: Lock REQUEST received while idle.\n"); 
                    break;
                }
            case 2:
                {
                    dbg("TestP1", 
                        "App: Higher priority REQUEST received while holding lock.\n"); 
                    break;
                }
            default: break;
        }
    }

    event void VirtualLock.lockConflict() {
        dbg("TestP1", 
            "App: Received CONFLICT from some higher priority neighbor.\n"); 
    }

    event void VirtualLock.lockViolation(uint32_t metric) {
        dbg("TestP1", 
            "App: CONFLICT received while holding lock!!!\n");
        dbg("TestP1Eval", "APP_%s_VIOLATION\n", sim_time_string());
    }

    event void Boot.booted()
    {
        op = 0;
        waittime = 1024;
        holdtime = 256;
        //holdtime = 2048;
        max_iterations = 1;
        curr_iterations = 0;
        state = 0;
        done = 0;
        dbg("TestP1", "App: Node booted.\n");
        call RadioControl.start();
#ifdef TEST_relax
        call VirtualLock.enableRandomAccess();
#endif
    }

    event void RadioControl.startDone(error_t err) {
        // let it discover neighbors for first 240+(dtfire/128) seconds
        uint32_t dtfire = 240*1024L;
        //uint32_t dtfire = (call Random.rand32() % 128) + 240*1024L;
        dbg("TestP1", "App: Enabling PTZ control for camera.\n");
        dbg("TestP1", "App: Neighbor discovery started.\n");
        call CameraControl.enable((void*)&dtfire);
    }

    event void CameraControl.enabled() {
        // Camera has been enabled. All neighbors must have been discovered.
        post dummyTask();
    }

    event void TestTimer.fired() {
        post dummyTask();
    }

    event void CameraControl.setDone(ptz_config_t* params) { }
    event void CameraConfig.changed() { }
    event void RadioControl.stopDone(error_t err) { }

}

