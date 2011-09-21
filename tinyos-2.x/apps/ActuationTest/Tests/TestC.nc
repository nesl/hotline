

// Comparing parallel operation using TestP2 module
//#define PARALLEL_TEST

#include "Range.h"

// Routing/Transport layer selections
#define USE_BROADCAST
//#define USE_LINEROUTE
//#define RELIABLE

// Number of nodes required for Zone/DIP
#define NUM_NODES   (GRID_SIZE*GRID_SIZE)

configuration TestC
{
}

implementation
{
    components MainC, ActiveMessageC;
    components new TimerMilliC() as TimerC1;
    components PTZCameraC;

#ifdef PARALLEL_TEST
    components TestP2, RandomC;
    TestP2.Boot -> MainC;
    TestP2.RadioControl -> ActiveMessageC;
    TestP2.TestTimer -> TimerC1;

    TestP2.VirtualLock -> PTZCameraC;
    TestP2.CameraConfig -> PTZCameraC;
    TestP2.CameraControl -> PTZCameraC;
    TestP2.Random -> RandomC;
#else
    components TestP1, RandomC;
    TestP1.Boot -> MainC;
    TestP1.RadioControl -> ActiveMessageC;
    TestP1.TestTimer -> TimerC1;

    TestP1.VirtualLock -> PTZCameraC;
    TestP1.CameraConfig -> PTZCameraC;
    TestP1.CameraControl -> PTZCameraC;
    TestP1.Random -> RandomC;
#endif
}

