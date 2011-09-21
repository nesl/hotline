

//#define RELIABLE

/////////////////////////////////////
//#define INF_BLINKM
////////////////////////////////////

//#define REAL_WORLD

#ifndef REAL_WORLD
#include "Range.h"
#endif

#include "SharedVar.h"
//#include "Neighbor.h"

//#define USE_BLINKM
#define USE_BROADCAST
#define GRID_SIZE   5
#define NUM_NODES   (GRID_SIZE*GRID_SIZE)

configuration PtzCameraAppC
{
}

implementation
{
    components MainC, ActiveMessageC;

    components PtzCameraAppP, RandomC;
    components new TimerMilliC() as TimerC1;
    components PTZCameraC, LedsC;
    components ShareDataC;

#ifdef REAL_WORLD
    components Pose2dC;
    PtzCameraAppP.Pose -> Pose2dC;
#endif
#ifdef USE_BLINKM
    components BlinkMC;
    PtzCameraAppP.BlinkM -> BlinkMC;
#endif
    
    PtzCameraAppP.Boot -> MainC;
    PtzCameraAppP.RadioControl -> ActiveMessageC;
    PtzCameraAppP.TestTimer -> TimerC1;
    PtzCameraAppP.VirtualLock -> PTZCameraC;
    PtzCameraAppP.CameraConfig -> PTZCameraC;
    PtzCameraAppP.CameraControl -> PTZCameraC;
    PtzCameraAppP.Random -> RandomC;
    PtzCameraAppP.Leds -> LedsC;
    PtzCameraAppP.NeighborTable -> PTZCameraC.NeighborTable[unique("NeighborTable")];
    PtzCameraAppP.Pan -> ShareDataC.SharedVariable[UQ_SHARED_VAR];
    PtzCameraAppP.Zoom -> ShareDataC.SharedVariable[UQ_SHARED_VAR];

    ShareDataC.NeighborTable ->
        PTZCameraC.NeighborTable[unique("NeighborTable")];
}

