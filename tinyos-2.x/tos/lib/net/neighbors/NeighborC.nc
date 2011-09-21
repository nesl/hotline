#include "Neighbor.h"

configuration NeighborC {
    provides interface StdControl;
    provides interface NeighborTable[uint8_t id];

    uses interface Zone;
    uses interface Timer<TMilli> as StampTimer;
}
implementation {
    components NeighborP, MainC;
    components new QueueC(am_addr_t, NEIGHBOR_TABLE_SIZE) as ZoneQueueC;

    StdControl = NeighborP;
    NeighborTable = NeighborP;
    Zone = NeighborP;
    StampTimer = NeighborP;

    MainC.SoftwareInit -> NeighborP;
    NeighborP.ZoneChangeQueue -> ZoneQueueC;

}
  
