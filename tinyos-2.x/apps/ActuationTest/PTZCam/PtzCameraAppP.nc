
#ifdef REAL_WORLD
#include <printf.h>
#include <coord2d.h>
#endif

#include <Camera.h>
#include <locks.h>
#include <Timer.h>

module PtzCameraAppP
{
    uses interface RawActControl<ptz_config_t> as CameraControl;
    uses interface PhysicalConfig<pose2d_t> as CameraConfig;
    uses interface VirtualLock;

    uses interface Random;

    uses interface SplitControl as RadioControl;
    uses interface Boot;

    uses interface Timer<TMilli> as TestTimer;
    uses interface Leds;

    uses interface NeighborTable;
    uses interface SharedVariable as Pan;
    uses interface SharedVariable as Zoom;
    
#ifdef REAL_WORLD
    uses interface PhysicalConfig<pose2d_t> as Pose;
#endif
#ifdef USE_BLINKM
    uses interface BlinkM;
#endif
}
implementation
{
    int8_t op = 0;
    uint8_t state = 0;
    uint8_t blink_state = 0;
    uint32_t selfmetric;
    uint32_t waittime, holdtime, requesttime;
    uint16_t max_iterations;
    uint16_t curr_iterations = 0;
    uint8_t done = 0;

#ifdef REAL_WORLD
    uint32_t sim_time_string() {
        return call TestTimer.getNow();
    }
#endif

    task void dummyTask() {
        switch (op) {
            case 0:
                {
                    state = 1;
                    curr_iterations++;
                    selfmetric = call TestTimer.getNow();
                    dbg("TestP1", "App: Trying to acquire lock.\n");
                    dbg("TestP1Eval", "APP_%s_ACQUIRE_%u_%u\n", 
                            sim_time_string(), waittime, selfmetric);
#ifdef REAL_WORLD
                    printf("DEBUG (%d): ", TOS_NODE_ID);
                    printf("APP_%ld_ACQUIRE_%ld_%ld\n", 
                            sim_time_string(), waittime, selfmetric);
                    //{
                    //    pose2d_t *p = call Pose.getGlobalPose();
                    //    printf("APP_%u_POSE_%u_%u\n", TOS_NODE_ID, p->loc.x,
                    //            p->loc.y);
                    //}
                    //printf("Iteration: Current-%u Max-%u\n", 
                    //        curr_iterations, max_iterations);
                    printfflush();
#endif
                    call VirtualLock.setPriority(selfmetric);
                    call VirtualLock.acquireLock(holdtime);
                    call Leds.led0Toggle();
                    break;
                }
            case 2:
                {
                    call VirtualLock.releaseLock();
                    call Leds.led2Toggle();
                    state = 0;
                    dbg("TestP1", "App: Lock released.\n");
                    dbg("TestP1Eval", "APP_%s_RELEASE\n", sim_time_string());
#ifdef REAL_WORLD
                    printf("DEBUG (%d): ", TOS_NODE_ID);
                    printf("APP_%ld_RELEASE\n", sim_time_string());
                    printfflush();
#endif
#ifdef INF_BLINKM
                    {
                        // Start another iteration after 3.3 seconds.
                        // Max PTZ change time.
                        uint32_t dtfire = 3380;
                        op = 0;
                        call TestTimer.startOneShot(dtfire);
                    }
#else
                    if ( curr_iterations < max_iterations ) {
                        // Start another iteration after 3.3 seconds.
                        // Max PTZ change time.
                        uint32_t dtfire = 3380;
                        op = 0;
                        call TestTimer.startOneShot(dtfire);
                    } else {
                        dbg("TestP1", "App: End of Work.\n");
                        done = 1;
                        op = 3;
                        // Start timer to signal end of work
                        //call TestTimer.startOneShot(2*1024);
                    }
#endif
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
#ifdef REAL_WORLD
                    printf("DEBUG (%d): ", TOS_NODE_ID);
                    printf("APP_%ld_GRANTED_%ld\n", 
                            sim_time_string(), selfmetric);
                    printfflush();
#endif
#ifdef USE_BLINKM
                    if (blink_state == 0) {
                        call BlinkM.fade_to_rgb_color(0xff,0x00,0x00);
                    } else if (blink_state == 1) {
                        call BlinkM.fade_to_rgb_color(0x00,0x00,0xff);
                    }
#endif
                    call Leds.led2Toggle();
                    call TestTimer.startOneShot(256);
                    op = 2;
                    state = 2;
                    break;
                }
            case LOCK_GRANT_TRY_EXPIRED:
                {
                    dbg("TestP1", 
                            "App: Lock try time expired.\n");
                    dbg("TestP1Eval", "APP_%s_TRYEXPIRED\n", sim_time_string());
                    // Try to acquire lock again
                    call VirtualLock.acquireLock(holdtime);
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
                            "App: Lock request received while idle.\n"); 
                    break;
                }
            case 2:
                {
                    dbg("TestP1", 
                            "App: Higher priority request received while holding lock.\n"); 
                    break;
                }
            default: break;
        }
    }

    event void VirtualLock.lockConflict() {
        dbg("TestP1", 
                "App: Some higher priority neighbor has requested a lock or is holding it.\n"); 
    }

    event void VirtualLock.lockViolation(uint32_t metric) {
        dbg("TestP1", 
                "App: Hold msg received while holding lock.\n");
        dbg("TestP1Eval", "APP_%s_VIOLATION\n", sim_time_string());
#ifdef REAL_WORLD
        printf("DEBUG (%d): ", TOS_NODE_ID);
        printf("APP_%ld_VIOLATION\n", sim_time_string());
        printfflush();
#endif
    }

    event void Boot.booted()
    {
        op = 0;
        // Max neighborhood size = 5.
        // 1-hop communication. 100ms round trip per hop.
        requesttime = 512;
        waittime = 1024;
        holdtime = 2048;
        // Fixed but different number of iterations for each node: [3, 5]
#ifdef REAL_WORLD
        max_iterations = (call Random.rand16() % 3) + 3;
#else
        max_iterations = (TOS_NODE_ID % 3) + 3;
#endif
        curr_iterations = 0;
        state = 0;
        // Simulation completion status
        done = 0;
        dbg("TestP1", "App: Node booted.\n");
        call RadioControl.start();
        call VirtualLock.enableRandomAccess();
        call VirtualLock.setWaitPeriod(waittime);
        call VirtualLock.setRequestPeriod(requesttime);
        call Leds.led0On();
#ifdef USE_BLINKM
        blink_state = 0;
        call BlinkM.stop_script();
        call BlinkM.set_fade_speed(10);
#endif
    }

    event void RadioControl.startDone(error_t err) {
        // let it discover neighbors for first 120+(dtfire/1024) seconds
        uint32_t dtfire = (call Random.rand16() % 100) + 120*1024L;
        dbg("TestP1", "App: Enabling PTZ control for camera.\n");
        dbg("TestP1", "App: Neighbor discovery started.\n");
        call CameraControl.enable((void*)&dtfire);
        call Leds.led1On();
    }

    event void CameraControl.enabled() {
        // Camera has been enabled. All neighbors must have been discovered.
        post dummyTask();
        call Leds.led2On();
    }

    event void TestTimer.fired() {
        post dummyTask();
    }

    event void Pan.changed(am_addr_t n) { }
    event void Zoom.changed(am_addr_t n) { }

    event void CameraControl.setDone(ptz_config_t* params) { }
    event void CameraConfig.changed() { }
    event void RadioControl.stopDone(error_t err) { }
    event void NeighborTable.neighborAdded(int8_t idx) { }
    event void NeighborTable.neighborRemoved(int8_t idx) { }

#ifdef REAL_WORLD
    event void Pose.changed() { }
#endif
#ifdef USE_BLINKM
    event void BlinkM.set_rgb_colorDone(error_t error)
    {
    }

    event void BlinkM.stop_scriptDone(error_t error)
    {
    }

    async event void BlinkM.get_rgb_colorDone(error_t error, uint8_t red, uint8_t green, uint8_t blue)
    {
    }

    event void BlinkM.fade_to_rgb_colorDone(error_t error)
    {
        if (blink_state == 0) {
            blink_state = 1;
        } else if (blink_state == 1) {
            blink_state = 0;
        }
    }

    event void BlinkM.set_fade_speedDone(error_t error)
    {
        call BlinkM.fade_to_rgb_color(0x00,0x00,0xff);
    }

    event void BlinkM.fade_to_hsb_colorDone(error_t error)
    {
    }
#endif

}

