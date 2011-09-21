
module ZoneCommP {
    provides interface Zone;
    provides interface Init;

    uses interface Packet;
    uses interface AMPacket;
    uses interface AMSend;
    uses interface Receive;

    uses interface NbrTrickleTimer as BeaconTimer;
}

implementation {

    bool diss_started;
    message_t pkt;
    uint32_t pktseq;
    bool busy;

    typedef nx_struct beacon_t {
        nx_uint32_t seq;
        nx_am_addr_t src;
    } beacon_t;

    /********* Private functions ***********/
    error_t send_beacon() {
        beacon_t *b = NULL;
        if ( !diss_started ) return FAIL;
        if ( busy ) return FAIL;

        b = (beacon_t*)(call Packet.getPayload(&pkt, 0));
        b->src = call AMPacket.address();
        b->seq = pktseq;

        if (call AMSend.send(AM_BROADCAST_ADDR,
                             &pkt,
                             sizeof(beacon_t)) == SUCCESS) {
            busy = TRUE;
            return SUCCESS;
        }
        return FAIL;
    }

    /********* Public functions ***********/

    command error_t Init.init() {
        diss_started = FALSE;
        pktseq = 0;
        busy = FALSE;
        return SUCCESS;
    }

    command error_t Zone.enable() {
        if ( diss_started ) return SUCCESS;
        if ( call BeaconTimer.start() != SUCCESS ) {
            return FAIL;
        }
        diss_started = TRUE;
        send_beacon();
        return SUCCESS;
    }

    command error_t Zone.disable() {
        if ( diss_started ) {
            diss_started = FALSE;
            call BeaconTimer.stop();
        }
        return SUCCESS;
    }

    command error_t Zone.set(uint8_t *newzone) {
        if ( !diss_started ) return FAIL;
        call BeaconTimer.reset();
        return SUCCESS;
    }
 
    command uint8_t* Zone.get(am_addr_t node_addr) {
        return NULL;
    }

    command bool Zone.intersects(am_addr_t nbr) {
        return TRUE;
    }

    event bool BeaconTimer.fired() {
        if ( !diss_started ) return FALSE;
        if ( send_beacon() == SUCCESS ) return TRUE;
        return FALSE;
    }

    event void AMSend.sendDone(message_t* msg, error_t err) {
        if (&pkt == msg) {
            busy = FALSE;
            if ( err == SUCCESS ) {
                pktseq++;
            }
        }
    }

    event message_t* Receive.receive(message_t* msg, void *payload,
                                     uint8_t len) {
        beacon_t *b = (beacon_t*)payload;
        if ( !diss_started ) return msg;
        if ( !signal Zone.changed(b->src) ) {
            // New node will be added in neighbor table
            call BeaconTimer.reset();
        }
        return msg;
    }

}
