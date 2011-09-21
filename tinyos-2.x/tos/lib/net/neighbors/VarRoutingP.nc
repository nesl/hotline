
#ifdef REAL_WORLD
#include <printf.h>
#endif

#include "Neighbor.h"

module VarRoutingP {
    provides interface Send;
    provides interface Receive;
    provides interface Init;
    provides interface DebugLog2;
    
    uses interface Queue<am_addr_t> as UpdateQueue;

    uses interface Packet;
    uses interface AMPacket;
    uses interface AMSend;
    uses interface Receive as SubReceive;

    uses interface NeighborTable;
}

implementation {

    typedef nx_struct {
        nx_am_addr_t dest;
    } rt_hdr_t;

    bool busy = FALSE;
    message_t *pkt;
    uint8_t length;

    // Only for logging purposes
    bool print_dbg;
    uint8_t num_used;
    uint32_t pktseq;

    /********** Private functions **********/
    
#ifdef REAL_WORLD
#else
#endif

    /************* Private functions *************/

    void reset_tx() {
        print_dbg = FALSE;
        busy = FALSE;
        pkt = NULL;
        length = 0;
    }

    void purgeUpdateQueue() {
        while ( !call UpdateQueue.empty() ) {
            call UpdateQueue.dequeue();
        }
    }

    /**************** Tasks ******************/

    task void processUpdateQueue() {
        am_addr_t next_node;
        rt_hdr_t *hdr;
        uint8_t total_len = length + sizeof(rt_hdr_t);

        if ( call UpdateQueue.empty() || (pkt==NULL) ) {
            return;
        }

        // Get next destination address
        next_node = call UpdateQueue.head();
        // Fill up the transport header information
        hdr = (rt_hdr_t*)(call Packet.getPayload(pkt, total_len));
        hdr->dest = next_node;
        // Send the message
        dbg("ShareDataP", "Routing: Sending- to:%u len:%u. ", next_node, total_len);
        if (call AMSend.send(next_node, 
                             pkt,
                             total_len) == SUCCESS) {
            dbg_clear("ShareDataP", "Success.\n");
        } else {
            dbg_clear("ShareDataP", "Fail.\n");
            post processUpdateQueue();
        }
    }

    /***************** Commands ****************/

    command error_t Init.init() {
        reset_tx();
        return SUCCESS;
    }

    command void DebugLog2.printLog(uint32_t seq, uint8_t num) {
        print_dbg = TRUE;
        pktseq = seq;
        num_used = num;
    }

    command error_t Send.cancel(message_t *msg) {
        purgeUpdateQueue();
        reset_tx();
    }

    command void* Send.getPayload(message_t *msg, uint8_t len) {
        uint8_t *m = (uint8_t*)call Packet.getPayload(msg, len+sizeof(rt_hdr_t));
        return m+sizeof(rt_hdr_t);
    }

    command uint8_t Send.maxPayloadLength() {
        return call Packet.maxPayloadLength() - sizeof(rt_hdr_t);
    }

    command error_t Send.send(message_t *msg, uint8_t len) {
#ifndef USE_BROADCAST
        int8_t n = -1;
#endif
        if ( busy ) return EBUSY;
        busy = TRUE;
        // Store msg and length for tx
        pkt = msg;
        length = len;
#ifdef USE_BROADCAST
        call UpdateQueue.enqueue(AM_BROADCAST_ADDR);
#else
        for ( n=call NeighborTable.getFirst(); n!=-1;
                n=call NeighborTable.getNext() ) {
            am_addr_t naddr = call NeighborTable.getAddress(n);
            call UpdateQueue.enqueue(naddr);
        }
#endif
        dbg("ShareDataP", "Send update request enqueued in Routing module.\n");
        post processUpdateQueue();
        return SUCCESS;
    }

    /***************** Events ****************/


    event void AMSend.sendDone(message_t* msg, error_t err) {
        if (pkt == msg) {
            dbg("ShareDataP", "Routing: Update send done.\n");
            if ( err == SUCCESS ) {
                call UpdateQueue.dequeue();
                if ( print_dbg ) {
                    dbg("ShareDataPEval", "SVR_%s_TX_%u_%u\n",
                            sim_time_string(), pktseq, num_used);
                }
                if ( call UpdateQueue.empty() ) {
                    // Pkt sent to all nodes
                    signal Send.sendDone(msg, err);
                    reset_tx();
                } else {
                    // Some nodes left
                    post processUpdateQueue();
                }
            } else {
                // Failed. Send again.
                post processUpdateQueue();
            }
        }
    }

    event message_t* SubReceive.receive(message_t* msg, void *payload, 
                                     uint8_t len) {
        rt_hdr_t *hdr = (rt_hdr_t *)payload;
        am_addr_t destAddr = hdr->dest;
        am_addr_t self = call AMPacket.address();
        uint8_t *data = (uint8_t*)((uint8_t*)payload+sizeof(rt_hdr_t));
        
        dbg("ShareDataP", "Routing: Rcvd pkt from node %u, for %u, with len %u.\n",
                call AMPacket.source(msg), hdr->dest, len);
        if ( (destAddr == self) || 
             (destAddr == AM_BROADCAST_ADDR) ) {
            // Signal receive to the app.
            signal Receive.receive(msg, data, len-sizeof(rt_hdr_t));
        }

        return msg;
    }

    event void NeighborTable.neighborAdded(int8_t idx) {}
    event void NeighborTable.neighborRemoved(int8_t idx) {}

}

