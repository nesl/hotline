
#include "route_fragment.h"
#include <ring.h>

module RouteFragmentP {
    provides interface Token;
    provides interface Init;
    provides interface SplitControl as RingControl;
    
    uses interface SplitControl as SourceControl;
    uses interface Packet;
    uses interface AMSend as TokenSend;
    uses interface Receive as TokenReceive;
    uses interface AMSend as AckSend;
    uses interface Receive as AckReceive;

    uses interface Pool<message_t>;
    uses interface Timer<TMilli>;
}

implementation {

    bool busy = FALSE;  // For sending acks
    uint16_t curr_token;
    uint8_t curr_seq;
    bool was_acked, started;
    state_t st;
    uint32_t retry_period;
    message_t *ackpkt;
    // Saved packet for resending token
    message_t *pkt;
    am_addr_t pktdest;
    uint8_t total_len;

    /********** Private functions **********/
    
    void dumpEvalString(tr_hdr_t *hdr, uint8_t type, am_addr_t dest, bool isTx) {
        dbg("RoutePEval", "RING_%s_", sim_time_string());
        switch (type) {
            case RING_TOKEN: {
                dbg_clear("RoutePEval", "TOKEN_%u_", hdr->token);
                break;
            }
            case RING_ACK: {
                dbg_clear("RoutePEval", "ACK_%u_", hdr->token);
                break;
            }
            default: {
                dbg_clear("RoutePEval", "UNKNOWN_0_");
                break;
            }
        }
        if ( isTx ) {
            dbg_clear("RoutePEval", "TX_%u\n", dest);
        } else {
            dbg_clear("RoutePEval", "RX_%u\n", hdr->src); 
        }
    }

    error_t tx_token(uint16_t token, uint8_t frag, uint8_t seq, 
            am_addr_t dest, void *data, uint8_t len) {
        uint8_t *pd = NULL;
        tr_hdr_t *hdr = NULL;
        error_t ret = SUCCESS;
        pkt = call Pool.get();
        if ( pkt == NULL ) return ENOMEM;
        
        total_len = len + sizeof(tr_hdr_t);
        hdr = (tr_hdr_t*)(call Packet.getPayload(pkt, total_len));
        if ( hdr == NULL ) {
            // Free up pkt memory
            call Pool.put(pkt);
            return ENOMEM;
        }
        // Set the transport header
        hdr->token = token;
        hdr->src = TOS_NODE_ID;
        hdr->frag = frag;
        hdr->seq = seq;
        pktdest = dest;   // Ultimate destination
        //pktdest = right_n[TOS_NODE_ID];   // Ultimate destination
        // Copy data
        pd = (uint8_t*)(hdr + 1);
        memcpy(pd, data, len);
        dumpEvalString(hdr, RING_TOKEN, pktdest, TRUE);
        ret = call TokenSend.send(pktdest, pkt, total_len);
        if ( ret != SUCCESS ) {
            call Pool.put(pkt);
        }
        return ret;
    }

    error_t resend_token() {
        tr_hdr_t *hdr = (tr_hdr_t*)(call Packet.getPayload(pkt, 0));
        dumpEvalString(hdr, RING_TOKEN, pktdest, TRUE);
        return call TokenSend.send(pktdest, pkt, total_len);
    }

    void send_ack(tr_hdr_t* hdr) {
        tr_hdr_t* ackhdr;

        if ( busy ) return;

        ackpkt = call Pool.get();
        if ( ackpkt == NULL ) return;

        ackhdr = (tr_hdr_t*)call Packet.getPayload(ackpkt, sizeof(tr_hdr_t));
        if ( ackhdr == NULL ) {
            call Pool.put(ackpkt);
            return;
        }

        ackhdr->token = hdr->token;
        ackhdr->frag = hdr->frag;
        ackhdr->seq = hdr->seq;
        ackhdr->src = TOS_NODE_ID;
        
        dumpEvalString(ackhdr, RING_ACK, hdr->src, TRUE);

        if (call AckSend.send(hdr->src, 
                              ackpkt, 
                              sizeof(tr_hdr_t)) == SUCCESS) {
            busy = TRUE;
        } else {
            call Pool.put(ackpkt);
        }
    }

    /**************** Tasks ******************/

    /***************** Commands ****************/

    command error_t Init.init() {
        busy = FALSE;
        was_acked = FALSE;
        started = FALSE;
        curr_token = 0;
        curr_seq = 0;
        pkt = NULL;
        ackpkt = NULL;
        st = STATE_IDLE;
        retry_period = DEFAULT_RETRY_PERIOD;
        return SUCCESS;
    }

    command error_t RingControl.start() {
        if ( started ) return EALREADY;
        started = TRUE;
        return call SourceControl.start();
    }

    command error_t RingControl.stop() {
        if ( !started ) return EALREADY;
        started = FALSE;
        return call SourceControl.stop();
    }

    event void SourceControl.startDone(error_t ret) {
        if ( ret != SUCCESS ) {
            started = FALSE;
        }
        signal RingControl.startDone(ret);
    }

    event void SourceControl.stopDone(error_t ret) {
        if ( ret != SUCCESS ) {
            started = TRUE;
        }
        signal RingControl.stopDone(ret);
    }

    command uint8_t Token.maxPayloadLength() {
        return call Packet.maxPayloadLength() - sizeof(tr_hdr_t);
    }

    command void Token.setRetryPeriod(uint32_t p) {
        retry_period = p;
    }

    command error_t Token.send(uint16_t token, uint8_t frag, uint8_t seq, 
            am_addr_t dest, void *data, uint8_t len) {
        if ( !started ) return FAIL;
        switch (st) {
            case STATE_WAITING: {
                //return EBUSY;
                // Stop the ack timer
                call Timer.stop();
                // Free up the current pkt
                call Pool.put(pkt);
                // Fall through to send the new token
            }
            case STATE_IDLE: {
                // Tx token
                if ( tx_token(token, frag, seq, dest, data, len) == SUCCESS ) {
                    // Update current token number and ack status
                    curr_token = token;
                    curr_seq = seq;
                    was_acked = FALSE;
                    st = STATE_SENDING;
                } else {
                    st = STATE_IDLE;    // Reqd when falls through STATE_WAITING
                    return FAIL;
                }
                break;
            }
            case STATE_SENDING: {
                return EBUSY;
            }
            default: return FAIL;
        }
        return SUCCESS;
    }

    /***************** Events ****************/

    event void TokenSend.sendDone(message_t* msg, error_t err) {
        if ( !started ) return;
        if (pkt == msg) {
            // RING_TOKEN sent
            switch (st) {
                case STATE_WAITING: 
                case STATE_IDLE: {
                    // Should not happen. Ignore
                    break;
                }
                case STATE_SENDING: {
                    if ( err == SUCCESS ) {
                        if ( was_acked ) {
                            // The current token was acked (almost) in parallel with
                            // the retransmission.
                            st = STATE_IDLE;
                            // Free the pkt as it will not be resent.
                            call Pool.put(pkt);
                            // Do not signal sendDone to the app here as it was an
                            // internal resend.
                            // Signal acked.
                            signal Token.acked(curr_token, curr_seq);
                        } else {
                            // Start the ack timer
                            call Timer.startOneShot(retry_period);
                            st = STATE_WAITING;
                            // Signal the app
                            signal Token.sendDone(curr_token, curr_seq, err);
                        }
                    } else {
                        // Sending failed
                        st = STATE_IDLE;
                        call Pool.put(pkt);
                        if ( was_acked ) {
                            // Resend failed. But previous send was acked.
                            // So, signal the app.
                            signal Token.acked(curr_token, curr_seq);
                        } else {
                            // Send failed. And it wasn't acked either.
                            // Signal the app
                            signal Token.sendDone(curr_token, curr_seq, err);
                        }
                    }
                    break;
                }
                default: break;
            }
        } 
    }

    event message_t* TokenReceive.receive(message_t* msg, void *payload, 
                                        uint8_t len) {
        tr_hdr_t* hdr = (tr_hdr_t*)payload;
        uint8_t* data = (uint8_t*)(hdr+1);
        if ( !started ) return msg;
        // Token is meant for this node.
        dumpEvalString(hdr, RING_TOKEN, 0, FALSE);
        // Send ack.
        send_ack(hdr);
        //Signal app.
        signal Token.receive(hdr->token, hdr->frag, hdr->seq, data, len-sizeof(tr_hdr_t));
        return msg;
    }
    
    event void Timer.fired() { 
        if ( !started ) return;
        switch (st) {
            case STATE_WAITING: { 
                // Send the packet again.
                if ( resend_token() == SUCCESS ) {
                    st = STATE_SENDING;
                } else {
                    // Token resend failed for some reason.
                    // Stay on this state and restart the timer.
                    call Timer.startOneShot(retry_period);
                }
                break;
            }
            case STATE_IDLE: 
            case STATE_SENDING: {
                // Sending a new token. Ignore.
                break;
            }
            default: break;
        }
    }
    
    event void AckSend.sendDone(message_t* msg, error_t err) {
        if (ackpkt == msg) {
            // RING_ACK sent
            busy = FALSE;
            call Pool.put(ackpkt);
        }
    }

    event message_t* AckReceive.receive(message_t* msg, void *payload, 
                                        uint8_t len) {
        tr_hdr_t* hdr = (tr_hdr_t*)payload;
        if ( !started ) return msg;
        dumpEvalString(hdr, RING_ACK, 0, FALSE);
        switch (st) {
            case STATE_WAITING: { 
                if ( (hdr->token==curr_token) &&
                        (hdr->seq==curr_seq) ) {
                    // Ack is for the current token and seq. SUCCESS!
                    call Timer.stop();
                    //dumpEvalString(hdr, RING_ACK, 0, FALSE);
                    was_acked = TRUE;
                    st = STATE_IDLE;
                    call Pool.put(pkt);
                    signal Token.acked(curr_token, curr_seq);
                }
                break;
            }
            case STATE_IDLE: {
                // Redundant ack. Ignore
                break;
            }
            case STATE_SENDING: {
                // Must be resending the current token.
                if ( (hdr->token==curr_token) &&
                       (hdr->seq==curr_seq) ) {
                    // Ack is for the current token and seq. SUCCESS!
                    was_acked = TRUE;
                    // App will be signalled acked in sendDone after the pkt
                    // is freed up.
                    //dumpEvalString(hdr, RING_ACK, 0, FALSE);
                }
                break;
            }
            default: break;
        }

        return msg;
    }
    
}

