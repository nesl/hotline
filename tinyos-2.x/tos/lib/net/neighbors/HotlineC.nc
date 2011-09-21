#include "Neighbor.h"
#include "SharedVar.h"

generic configuration HotlineC(uint8_t M) {
    provides interface SharedMemory;
    provides interface Sync;
    provides interface StdControl as Iterations;
    provides interface VirtualLock;
    provides interface NeighborTable[uint8_t id];
    provides interface Timer<TMilli>[uint8_t id];
    uses interface Zone;
    uses interface DebugLog;
}

implementation {
    components MainC;
    components new SharedMemoryP(M);
    components new CacheSyncLatestP(M) as CacheC;
    components SynchronizeP as SyncP;
    components ShareDataC;
    components VersionTimeP as VersionP;
    components TestVirtualLockPosC as VLockC;
    components NeighborC;

    components new TimerMilliC() as BaseTimerC;
    components new VirtualizeTimerC(TMilli, uniqueCount("HotlineTimer"))
        as VirtualTimerC;

    
    SharedMemory = SharedMemoryP;
    Sync = SyncP;
    Iterations = SyncP;
    DebugLog = SyncP;
    VirtualLock = VLockC;
    Zone = NeighborC;
    NeighborTable = NeighborC;
    Timer = VirtualTimerC;

    NeighborC.StampTimer -> VirtualTimerC.Timer[unique("HotlineTimer")];
    VersionP.Timer -> VirtualTimerC.Timer[unique("HotlineTimer")];

    ShareDataC.Version -> VersionP;
    ShareDataC.ShareDataTable -> NeighborC.NeighborTable[unique("NeighborTable")];
    ShareDataC.RoutingTable -> NeighborC.NeighborTable[unique("NeighborTable")];
    ShareDataC.RandomTimer -> VirtualTimerC.Timer[unique("HotlineTimer")];

    SharedMemoryP.SharedVariable -> ShareDataC;
    SharedMemoryP.Cache ->CacheC;

    SyncP.SharedVariable -> ShareDataC;
    SyncP.NeighborTable -> NeighborC.NeighborTable[unique("NeighborTable")];
    SyncP.NeighborDiscovery -> NeighborC;
    SyncP.StampTimer -> VirtualTimerC.Timer[unique("HotlineTimer")];

    CacheC.SharedVariable -> ShareDataC;
    CacheC.StampTimer -> VirtualTimerC.Timer[unique("HotlineTimer")];

    VLockC.NeighborTable -> NeighborC.NeighborTable[unique("NeighborTable")];

    VirtualTimerC.TimerFrom -> BaseTimerC;
}

  
