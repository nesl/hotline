
#include "ValveControl.h"
#include "Neighbor.h"
#include "locks.h"

configuration ValveControlC {
    provides interface RawActControl<valve_config_t> as ValveControl;
    provides interface PhysicalConfig<pose2d_t> as Config2d;
    provides interface VirtualLock;
}

implementation {
    components ValveControlP, MainC;
#ifdef RELIABLE
    components TestVirtualLockReliableC as VLockC;
#else
    components TestVirtualLockC as VLockC;
#endif
    components new Zone1dC(NUM_NODES) as ZoneC;
    components new TimerMilliC() as BaseTimerC;
    components new VirtualizeTimerC(TMilli, uniqueCount("ValveTimer")) as
                VirtualTimerC;
    components Pose2dC;

    ValveControl = ValveControlP;
    Config2d = ValveControlP;
    VirtualLock = VLockC;
    
    MainC.SoftwareInit -> ValveControlP;
    
    ValveControlP.BaseConfig2d -> Pose2dC;
    ValveControlP.Zone -> ZoneC;
    ValveControlP.NeighborDiscovery -> VLockC;
    ValveControlP.DummyActTimer -> VirtualTimerC.Timer[unique("ValveTimer")];
    ValveControlP.DiscoveryTimer -> VirtualTimerC.Timer[unique("ValveTimer")];
    VirtualTimerC.TimerFrom -> BaseTimerC;

    VLockC.Zone -> ZoneC;
}

