
#include "Camera.h"
#include "Neighbor.h"
#include "locks.h"

configuration PTZCameraC {
    provides interface RawActControl<ptz_config_t> as PTZControl;
    provides interface PhysicalConfig<pose2d_t> as Config2d;
    provides interface VirtualLock;
    //provides interface NeighborTable[uint8_t id];
}

implementation {
    components PTZCameraP, MainC;
    components TestVirtualLockPosC as VLockC;
    components new ZoneCircleC(NUM_NODES) as ZoneC;
    components new TimerMilliC() as BaseTimerC;
    components new VirtualizeTimerC(TMilli, uniqueCount("CameraTimer")) as
                VirtualTimerC;
    components Pose2dC, Vector2dC;
    components NeighborC;

    PTZControl = PTZCameraP;
    Config2d = PTZCameraP;
    VirtualLock = VLockC;
    //NeighborTable = NeighborC;
    
    MainC.SoftwareInit -> PTZCameraP;
    
    VLockC.NeighborTable -> NeighborC.NeighborTable[UQ_NBRTABLE];

    PTZCameraP.BaseConfig2d -> Pose2dC;
    PTZCameraP.Zone -> ZoneC;
    PTZCameraP.NeighborDiscovery -> NeighborC;
    PTZCameraP.Vector2d -> Vector2dC;
    PTZCameraP.DummyActTimer -> VirtualTimerC.Timer[unique("CameraTimer")];
    PTZCameraP.DiscoveryTimer -> VirtualTimerC.Timer[unique("CameraTimer")];

    VirtualTimerC.TimerFrom -> BaseTimerC;

    NeighborC.Zone -> ZoneC;
    NeighborC.StampTimer -> VirtualTimerC.Timer[unique("CameraTimer")];
}

