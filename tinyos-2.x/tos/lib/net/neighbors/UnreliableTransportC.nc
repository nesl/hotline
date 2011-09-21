
#include "locks.h"
#include "source_route.h"

configuration UnreliableTransportC {
    provides interface MsgTransport as Transport;
    uses interface Timer<TMilli> as StampTimer;
}
implementation {
    components MainC, UnreliableTransportP;
    components new QueueC(lock_queue_t*, LOCK_QUEUE_SIZE);
    components new PoolC(lock_queue_t, LOCK_QUEUE_SIZE);
#ifdef USE_BROADCAST
    components new AMSenderC(AM_VIRTUAL_LOCK) as RadioSend;
    components new AMReceiverC(AM_VIRTUAL_LOCK) as RadioRcv;
#else
    components SourceRouteC;
#endif

    Transport = UnreliableTransportP;
    StampTimer = UnreliableTransportP;

    MainC.SoftwareInit -> UnreliableTransportP;

    UnreliableTransportP.LockQueue -> QueueC;
    UnreliableTransportP.RequestPool -> PoolC;
#ifdef USE_BROADCAST
    UnreliableTransportP.Packet -> RadioSend;
    UnreliableTransportP.AMPacket -> RadioSend;
    UnreliableTransportP.AMSend -> RadioSend;
    UnreliableTransportP.Receive -> RadioRcv;
#else
    enum {
        phylock_route_id = UQ_SOURCE_ROUTE,
    };

    UnreliableTransportP.Packet -> SourceRouteC;
    UnreliableTransportP.AMPacket -> SourceRouteC;
    UnreliableTransportP.AMSend -> SourceRouteC.AMSend[phylock_route_id];
    UnreliableTransportP.Receive -> SourceRouteC.Receive[phylock_route_id];
#endif
}
  
