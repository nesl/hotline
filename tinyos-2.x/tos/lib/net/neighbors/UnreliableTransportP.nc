
#ifdef REAL_WORLD
#include <printf.h>
#endif

#include "Neighbor.h"
#include "locks.h"

module UnreliableTransportP {
    provides interface MsgTransport as Transport;
    provides interface Init;
    
    uses interface Pool<lock_queue_t> as RequestPool;
    uses interface Queue<lock_queue_t*> as LockQueue;

    uses interface Packet;
    uses interface AMPacket;
    uses interface AMSend;
    uses interface Receive;

    uses interface Timer<TMilli> as StampTimer;
}

implementation {

    bool busy = FALSE;
    uint32_t pktseq = 0;
    message_t pkt;

    /********** Private functions **********/
    
#ifdef REAL_WORLD
    uint32_t sim_time_string() {
        return call StampTimer.getNow();
    }

    void dumpEvalString(lock_packet_t *lockpkt, am_addr_t addr, bool isTx) {
        printf("DEBUG (%d): ", TOS_NODE_ID);
        printf("LOCK_%ld_", sim_time_string());
        switch (lockpkt->msgtype) {
            case LOCK_MSG_REQUEST: {
                printf("REQUEST_");
                break;
            }
            case LOCK_MSG_CONFLICT: {
                printf("CONFLICT_");
                break;
            }
            case LOCK_MSG_DONE: {
                printf("DONE_");
                break;
            }
            case LOCK_MSG_HOLD: {
                printf("HOLD_");
                break;
            }
            default: {
                printf("UNKNOWN_");
                break;
            }
        }
        // The ultimate destination determines whether this is BCAST or
        // 1-to-1
        if ( isTx ) {
            printf("TX_%u\n", lockpkt->destAddr);
        } else {
            printf("RX_%u_%u\n", lockpkt->destAddr, lockpkt->srcAddr);
        }
        printfflush();
    }
#else
    void dumpEvalString(lock_packet_t *lockpkt, am_addr_t addr, bool isTx) {
        dbg("TransportPEval", "LOCK_%s_", sim_time_string());
        switch (lockpkt->msgtype) {
            case LOCK_MSG_REQUEST: {
                dbg_clear("TransportPEval", "REQUEST_");
                break;
            }
            case LOCK_MSG_CONFLICT: {
                dbg_clear("TransportPEval", "CONFLICT_");
                break;
            }
            case LOCK_MSG_DONE: {
                dbg_clear("TransportPEval", "DONE_");
                break;
            }
            case LOCK_MSG_HOLD: {
                dbg_clear("TransportPEval", "HOLD_");
                break;
            }
            default: {
                dbg_clear("TransportPEval", "UNKNOWN_");
                break;
            }
        }
        // The ultimate destination determines whether this is BCAST or
        // 1-to-1
        if ( isTx ) {
            dbg_clear("TransportPEval", "TX_%u\n", lockpkt->destAddr);
        } else {
            dbg_clear("TransportPEval", "RX_%u_%u\n", 
                    lockpkt->destAddr, lockpkt->srcAddr);
        }
    }
#endif

    /************* Private functions *************/

    void purgeLockQueue() {
        while ( !call LockQueue.empty() ) {
            lock_queue_t *del = call LockQueue.dequeue();
            call RequestPool.put(del);
        }
    }

    /**************** Tasks ******************/

    task void processLockQueue() {
        lock_queue_t *nextmsg;
        lock_packet_t *lockpkt;

        if ( call LockQueue.empty() || busy ) {
            return;
        }

        nextmsg = call LockQueue.head();
        lockpkt = (lock_packet_t*)(call Packet.getPayload(&pkt, 0));
        memcpy(lockpkt, &nextmsg->data, sizeof(lock_packet_t));
        if ( lockpkt->srcAddr == call AMPacket.address() ) {
            // The msg originated at this node. Set seq number.
            lockpkt->seq = pktseq;
        }

        if (call AMSend.send(nextmsg->nextHop, 
                             &pkt,
                             sizeof(lock_packet_t)) == SUCCESS) {
            busy = TRUE;
            if ( lockpkt->srcAddr == call AMPacket.address() ) {
                // The msg originated at this node. Incr seq number.
                pktseq++;
                dumpEvalString(lockpkt, lockpkt->destAddr, TRUE);
            } // Else, its a forwarded msg.
        } else {
            post processLockQueue();
        }
    }

    /***************** Commands ****************/

    command error_t Init.init() {
        busy = FALSE;
        pktseq = 0;
        return SUCCESS;
    }

    command am_addr_t Transport.address() {
        return call AMPacket.address();
    }

    command void Transport.clearAll() {
        purgeLockQueue();
    }

    error_t do_send(lock_packet_t *lockpkt, am_addr_t nextHop) {
        error_t ret;
        // Allocate space for new request
        lock_queue_t *new_req = call RequestPool.get();
        if ( new_req == NULL ) return FAIL;
        // Copy request
        memcpy(&new_req->data, lockpkt, sizeof(lock_packet_t));
        // Put request into the queue
        new_req->retries = 0;
        new_req->acked = FALSE;
        new_req->nextHop = nextHop;
        ret = call LockQueue.enqueue(new_req);
        if ( ret == SUCCESS ) {
            post processLockQueue();
        } else {
            call RequestPool.put(new_req);
        }
        return ret;
    }

    command error_t Transport.send(lock_packet_t *lockpkt, am_addr_t destAddr) {
#ifdef USE_LINE_ROUTING
        am_addr_t srcAddr = lockpkt->srcAddr;
        if ( destAddr == AM_BROADCAST_ADDR ) {
            error_t ret = do_send(lockpkt, srcAddr+1);
            if ( ret == FAIL ) {
                // Not enough memory
                return ret;
            }
            if ( srcAddr == 0 ) {
                // Boundary node.
                return ret;
            }
            ret = do_send(lockpkt, srcAddr-1);
            if ( ret == FAIL ) {
                // Not enough memory. 
                // TODO: Remove previous msg too.
                return ret;
            }
            return ret;
        }
        if ( destAddr > srcAddr ) {
            return do_send(lockpkt, srcAddr+1);
        }
        if ( destAddr < srcAddr ) {
            if ( srcAddr == 0 ) return FAIL;
            return do_send(lockpkt, srcAddr-1);
        }
        return FAIL;    // should never reach here.
#else
        // Single hop routing => destAddr is the nextHop
        return do_send(lockpkt, destAddr);
#endif
    }

    command void Transport.setMaxRetries(uint8_t max) {}
    command void Transport.setRetryPeriod(uint32_t period) {}

    /***************** Events ****************/


    event void AMSend.sendDone(message_t* msg, error_t err) {
        if (&pkt == msg) {
            lock_queue_t *nextmsg = call LockQueue.dequeue();
            busy = FALSE;
            if ( nextmsg->data.srcAddr == call AMPacket.address() ) {
                // The msg originated at this node. Signal the app.
                signal Transport.sendDone(&nextmsg->data, nextmsg->data.destAddr, SUCCESS);
            }
            call RequestPool.put(nextmsg);
        }
        post processLockQueue();
    }

    event message_t* Receive.receive(message_t* msg, void *payload, 
                                     uint8_t len) {
        lock_packet_t *lock_pkt = (lock_packet_t*)payload;
        am_addr_t srcAddr = lock_pkt->srcAddr;
        am_addr_t destAddr = lock_pkt->destAddr;
        am_addr_t self = call AMPacket.address();
        message_t *ret = msg;
        
        if ( (destAddr == self) || 
             (destAddr == AM_BROADCAST_ADDR) ) {
            // Signal receive to the app.
            if (signal Transport.receive(lock_pkt, srcAddr) == NULL) {
                ret = NULL;
            }
        }

        if ( (self == 0) || (destAddr == self) ) {
            // Boundary node or sole destination node.
            return ret;
        }

#ifdef USE_LINE_ROUTING
        {
            // Forward this msg in the same direction. Find next hop.
            am_addr_t nextHop = 0;
            // Do not use destAddr for comparison as it could be BCAST addr.
            if ( srcAddr > self ) {
                nextHop = self - 1;
            } else {
                nextHop = self + 1;
            }
            do_send(lock_pkt, nextHop);
        }
#endif
        return ret;
    }
    
    event void StampTimer.fired() { }

}

