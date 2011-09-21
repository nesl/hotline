
#include "route_fragment.h"

generic configuration RingTransportC(uint16_t MAX_DATA_SIZE) {
    provides interface Ring;
    provides interface SplitControl as RingControl;
    uses interface Timer<TMilli>;
}
implementation {
    components MainC, RouteFragmentP;
    components new RingTransportP(MAX_DATA_SIZE) as TransportP;
    components SourceRouteC, ActiveMessageC;
    components new PoolC(message_t, 2); // 1 for pkt + 1 for ack

    Ring = TransportP;
    RingControl = RouteFragmentP;
    Timer = RouteFragmentP;

    RouteFragmentP.SourceControl -> ActiveMessageC;
    RouteFragmentP.Pool -> PoolC;
    RouteFragmentP.Packet -> SourceRouteC.Packet;
    RouteFragmentP.TokenSend -> SourceRouteC.AMSend[RING_TOKEN];
    RouteFragmentP.TokenReceive -> SourceRouteC.Receive[RING_TOKEN];
    RouteFragmentP.AckSend-> SourceRouteC.AMSend[RING_ACK];
    RouteFragmentP.AckReceive -> SourceRouteC.Receive[RING_ACK];
    
    MainC.SoftwareInit -> RouteFragmentP;
    MainC.SoftwareInit -> TransportP;

    TransportP.Token -> RouteFragmentP;
}

