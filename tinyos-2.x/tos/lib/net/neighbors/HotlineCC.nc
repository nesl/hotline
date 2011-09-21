#include "Neighbor.h"
#include "SharedVar.h"

generic configuration HotlineCC(uint8_t M) {
    provides interface SharedMemory;
    provides interface Sync;
    provides interface StdControl as Iterations;
    provides interface NeighborTable[uint8_t id];
    provides interface Timer<TMilli>[uint8_t id];
    uses interface Zone;
    uses interface EdgeWeight;
    uses interface DebugLog;
}
implementation {
    components MainC;
    components new SharedMemoryP(M);
    components new CacheSyncAvgP(M) as CacheC;
    components SynchronizeP as SyncP;
    components ShareDataC;
    components VersionSequenceP as VersionP;
    components NeighborC;

    components new TimerMilliC() as BaseTimerC;
    components new VirtualizeTimerC(TMilli, uniqueCount("HotlineTimer"))
        as VirtualTimerC;

    SharedMemory = SharedMemoryP;
    Sync = SyncP;
    Iterations = SyncP;
    DebugLog = SyncP;
    Zone = NeighborC;
    NeighborTable = NeighborC;
    Timer = VirtualTimerC;
    EdgeWeight = CacheC;

    NeighborC.StampTimer -> VirtualTimerC.Timer[unique("HotlineTimer")];

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
    CacheC.NeighborTable -> NeighborC.NeighborTable[unique("NeighborTable")];

    VirtualTimerC.TimerFrom -> BaseTimerC;
}

  
