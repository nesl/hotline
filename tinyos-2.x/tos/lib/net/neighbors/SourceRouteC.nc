#include "source_route.h"

configuration SourceRouteC {
    provides interface AMSend[uint8_t id];
    provides interface Receive[uint8_t id];
    provides interface Packet;
    provides interface AMPacket;
}

implementation {
    components MainC;
    components SourceRouteP, RouteManagerP;
    components new PoolC(message_t, MAX_QUEUE_LEN) as SrcPoolC;
    components new QueueC(msg_queue_t, MAX_QUEUE_LEN) as SrcQueueC;
    components new AMSenderC(AM_SOURCE_ROUTE) as RadioSend;
    components new AMReceiverC(AM_SOURCE_ROUTE) as RadioRcv;

    AMSend = SourceRouteP;
    Receive = SourceRouteP;
    Packet = SourceRouteP;
    AMPacket = RadioSend;

    MainC.SoftwareInit -> SourceRouteP;

    SourceRouteP.Route -> RouteManagerP;
    SourceRouteP.MsgPool -> SrcPoolC;
    SourceRouteP.MsgQueue -> SrcQueueC;

    SourceRouteP.SubPacket -> RadioSend;
    SourceRouteP.SubAMPacket -> RadioSend;
    SourceRouteP.SubAMSend -> RadioSend;
    SourceRouteP.SubReceive -> RadioRcv;
}

