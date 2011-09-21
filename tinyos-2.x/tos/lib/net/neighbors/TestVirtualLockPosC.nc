#include "Neighbor.h"
#include "locks.h"

configuration TestVirtualLockPosC {
    provides interface VirtualLock;
    uses interface NeighborTable;
}
implementation {
    components RandomC, MainC, UnreliableTransportC;
    components VirtualLockPositiveP as VirtualLockP;
    components new TimerMilliC() as BaseTimerC;
    components new VirtualizeTimerC(TMilli, uniqueCount("VirtualLockTimer")) as VirtualTimerC;

    components new PoolC(lock_packet_t, NEIGHBOR_TABLE_SIZE) as RcvPoolC;
    components new QueueC(lock_packet_t*, NEIGHBOR_TABLE_SIZE) as RcvQueueC;

    VirtualLock = VirtualLockP;
    NeighborTable = VirtualLockP;

    MainC.SoftwareInit -> VirtualLockP;

    UnreliableTransportC.StampTimer -> VirtualTimerC.Timer[unique("VirtualLockTimer")];
    
    VirtualLockP.Transport -> UnreliableTransportC;
    VirtualLockP.Random -> RandomC;
    VirtualLockP.RequestTimer -> VirtualTimerC.Timer[unique("VirtualLockTimer")];
    VirtualLockP.TryTimer -> VirtualTimerC.Timer[unique("VirtualLockTimer")];
    VirtualLockP.SendTimer -> VirtualTimerC.Timer[unique("VirtualLockTimer")];
    VirtualLockP.AppWaitTimer -> VirtualTimerC.Timer[unique("VirtualLockTimer")];
    VirtualLockP.RcvPool -> RcvPoolC;
    VirtualLockP.RcvQueue -> RcvQueueC;

    VirtualTimerC.TimerFrom -> BaseTimerC;
}

  
