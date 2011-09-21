#include "Neighbor.h"
#include "SharedVar.h"
#include "source_route.h"

configuration ShareDataC {
    provides interface SharedVariable;
    uses interface NeighborTable as ShareDataTable;
    uses interface NeighborTable as RoutingTable;
    uses interface Version;
    uses interface Timer<TMilli> as RandomTimer;
}

implementation {
    components ShareDataP, MainC, RandomC;
    components UnreliableVarTransportP as TransportP;
    components VarRoutingP as RoutingP;
    components new QueueC(am_addr_t, NEIGHBOR_TABLE_SIZE) as UpdateQueueC;
#ifdef USE_BROADCAST
    components new AMSenderC(AM_SHARED_VAR) as RadioSend;
    components new AMReceiverC(AM_SHARED_VAR) as RadioRcv;
#else
    components SourceRouteC;
#endif
    components new NbrTrickleTimerMilliC(128, 32*1024L) as UpdateTimerC;

    SharedVariable = ShareDataP;
    ShareDataTable = ShareDataP;
    Version = ShareDataP;
    RoutingTable = RoutingP;
    RandomTimer = TransportP;

    ShareDataP.VarTransport -> TransportP;
    ShareDataP.UpdateTimer -> UpdateTimerC;
    ShareDataP.Random -> RandomC;

    MainC.SoftwareInit -> ShareDataP;
    MainC.SoftwareInit -> TransportP;
    MainC.SoftwareInit -> RoutingP;

    TransportP.Send -> RoutingP;
    TransportP.Receive -> RoutingP.Receive;
    TransportP.DebugLog2 -> RoutingP;
    TransportP.Random -> RandomC;

    RoutingP.UpdateQueue -> UpdateQueueC;
#ifdef USE_BROADCAST
    RoutingP.Packet -> RadioSend;
    RoutingP.AMPacket -> RadioSend;
    RoutingP.AMSend -> RadioSend;
    RoutingP.SubReceive -> RadioRcv;
#else
    enum {
        svr_route_id = UQ_SOURCE_ROUTE,
    };

    RoutingP.Packet -> SourceRouteC;
    RoutingP.AMPacket -> SourceRouteC;
    RoutingP.AMSend -> SourceRouteC.AMSend[svr_route_id];
    RoutingP.SubReceive -> SourceRouteC.Receive[svr_route_id];
#endif

}

