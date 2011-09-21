
#include "source_route.h"

module SourceRouteP {
    provides interface Init;
    provides interface AMSend[uint8_t id];
    provides interface Receive[uint8_t id];
    provides interface Packet;
    
    uses interface Pool<message_t> as MsgPool;
    uses interface Queue<msg_queue_t> as MsgQueue;
    uses interface Route;

    uses interface Packet as SubPacket;
    uses interface AMPacket as SubAMPacket;
    uses interface AMSend as SubAMSend;
    uses interface Receive as SubReceive;
}

implementation {

    bool busy = FALSE;

    /************* Private functions *************/

    /**************** Tasks ******************/

    task void processMsgQueue() {
        msg_queue_t nextq;
        src_hdr_t *hdr = NULL;

        if ( call MsgQueue.empty() || busy ) {
            return;
        }

        nextq = call MsgQueue.head();
        hdr = (src_hdr_t*)(call SubPacket.getPayload(nextq.msg, 0));

        if (call SubAMSend.send(hdr->route[hdr->idx], 
                                nextq.msg, 
                                hdr->len+sizeof(src_hdr_t)) == SUCCESS) {
            busy = TRUE;
        } else {
            post processMsgQueue();
        }
    }

    /***************** Commands ****************/

    command error_t Init.init() {
        busy = FALSE;
        return SUCCESS;
    }

    command error_t AMSend.cancel[uint8_t id](message_t *msg) { 
        // Not supported
        return FAIL; 
    }

    command void* AMSend.getPayload[uint8_t id](message_t *msg, uint8_t len) { 
        uint8_t *p = call SubPacket.getPayload(msg, len+sizeof(src_hdr_t));
        return (void *)(p + sizeof(src_hdr_t));
    }
    
    command uint8_t AMSend.maxPayloadLength[uint8_t id]() { 
        return call SubPacket.maxPayloadLength() - sizeof(src_hdr_t);
    }
    
    command error_t AMSend.send[uint8_t id](am_addr_t addr, message_t *msg, uint8_t len) {
        msg_queue_t newpkt;
        src_hdr_t *hdr = NULL;

        // Get pointer to source routing header
        hdr = (src_hdr_t*)call SubPacket.getPayload(msg, len+sizeof(src_hdr_t));
        if ( hdr == NULL ) return ENOMEM;   // This won't happen usually

        // Set up the source routing header. Routes are set up with decreasing
        // indexes.
        hdr->type = id;
        hdr->len = len;
        hdr->idx = call Route.get(addr, hdr->route, SRC_MAX_HOPS) - 1;
        if ( hdr->idx < 0 ) return FAIL;

        // Enqueue the msg
        newpkt.action = ACTION_TX;
        newpkt.msg = msg;
        if ( call MsgQueue.enqueue(newpkt) != SUCCESS ) {
            return ENOMEM;
        }

        post processMsgQueue();
        return SUCCESS;
    }

    command void Packet.clear(message_t *msg){
        call SubPacket.clear(msg);
    }

    command void* Packet.getPayload(message_t *msg, uint8_t len){
        uint8_t *p = call SubPacket.getPayload(msg, len+sizeof(src_hdr_t));
        return (void *)(p + sizeof(src_hdr_t));
    }

    command uint8_t Packet.maxPayloadLength(){
        return call SubPacket.maxPayloadLength() - sizeof(src_hdr_t);
    }

#define HEADER  ((src_hdr_t *)(call SubPacket.getPayload(amsg, call SubPacket.maxPayloadLength())))

    command uint8_t Packet.payloadLength(message_t *amsg){
        return HEADER->len;
    }

    command void Packet.setPayloadLength(message_t *amsg, uint8_t len){
        HEADER->len = len;
        call SubPacket.setPayloadLength(amsg, len + sizeof(src_hdr_t));
    }

    /***************** Events ****************/

    event void SubAMSend.sendDone(message_t* msg, error_t err) {
        msg_queue_t nextq = call MsgQueue.head();
        if (nextq.msg == msg) {
            nextq = call MsgQueue.dequeue();
            busy = FALSE;
            if (nextq.action == ACTION_TX) {
                // Singal the action completion to upper layers
                src_hdr_t *hdr = (src_hdr_t*)call SubPacket.getPayload(msg, 0);
                signal AMSend.sendDone[hdr->type](msg, err);
            } else if (nextq.action == ACTION_FWD) {
                // Free up the sent msg
                call MsgPool.put(msg);
            }
        }
        post processMsgQueue();
    }

    event message_t* SubReceive.receive(message_t* msg, void *payload, 
                                     uint8_t len) {
        src_hdr_t *hdr = (src_hdr_t*)payload;
        
        // Check if the pkt reached correct next hop
        if ( hdr->route[hdr->idx] != call SubAMPacket.address() ) return msg;

        if ( --hdr->idx < 0 ) {
            // Packet has reached the destination
            // Signal upper layers.
            signal Receive.receive[hdr->type](msg, (void *)(hdr+1), hdr->len);
        } else {
            // Fwd the packet.
            msg_queue_t fwd;
            uint8_t *pktptr = NULL;
            // Allocate space for it.
            message_t *pkt = call MsgPool.get();
            if ( pkt == NULL ) return msg;  // Failed. Drop the pkt
            // Get pointer to put data into new pkt
            pktptr = (uint8_t*)call SubPacket.getPayload(pkt, len);
            if ( pktptr == NULL ) {
                // No space in new pkt for the rcvd pkt data
                call MsgPool.put(pkt);
                return msg;
            }
            // Enqueue the pkt for transmission
            fwd.action = ACTION_FWD;
            fwd.msg = pkt;
            if ( call MsgQueue.enqueue(fwd) != SUCCESS ) {
                // No space in queue. Drop the pkt.
                call MsgPool.put(pkt);
                return msg;
            }
            // Copy the rcvd msg into new pkt
            memcpy(pktptr, payload, len);
            post processMsgQueue();
        }
        return msg;
    }
    
    default event void AMSend.sendDone[uint8_t id](message_t* msg, error_t err) { }
    default event message_t* Receive.receive[uint8_t id](message_t* msg, 
            void *payload, uint8_t len) {
        return msg;
    }

}

