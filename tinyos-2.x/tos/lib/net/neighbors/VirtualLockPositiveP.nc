
#ifdef REAL_WORLD
#include <printf.h>
#endif

#include "Neighbor.h"
#include "locks.h"

#ifndef PACKET_LOSS_RATE
#define PACKET_LOSS_RATE    0
#endif

module VirtualLockPositiveP {
    provides interface VirtualLock;
    provides interface Init;
    
    uses interface NeighborTable;
    
    uses interface Random;

    uses interface Timer<TMilli> as RequestTimer;
    uses interface Timer<TMilli> as TryTimer;
    uses interface Timer<TMilli> as SendTimer;
    uses interface Timer<TMilli> as AppWaitTimer;

    uses interface MsgTransport as Transport;
    
    uses interface Pool<lock_packet_t> as RcvPool;
    uses interface Queue<lock_packet_t*> as RcvQueue;   // Main Tx queue
}

implementation {

    /* Lock status of this node */
    int8_t self = NEIGHBOR_TABLE_SIZE;
    int8_t status = LOCK_STATUS_IDLE;
    uint8_t req_tries = 0;
    /* Application specific parameters */
    bool random_enable = FALSE;
    uint32_t selfpriority = 0;
    uint32_t app_wait_period = MIN_APP_WAIT_PERIOD;
    /* Track and adapt to RT, msg count, hold times */
    uint32_t requestInitTime = 0;
    uint32_t ext_holdtime = 0;
    uint32_t holdfactor = DEFAULT_HOLD_FACTOR;
    uint32_t current_rt = 0;
    uint32_t current_msgcount = 0;
    /* Track detected violations */
    uint32_t total_trans = 0;
    /* Lock status of neighbors */
    lock_t node_locks[NEIGHBOR_TABLE_SIZE+1];

    /********** Private functions **********/
    
    void dumpNbrTable() {
        int8_t n;
        dbg("VirtualLockP",
            "Node Table: Lock status -- %u\n", status);
        for ( n=call NeighborTable.getFirst(); 
              n!=-1; n=call NeighborTable.getNext() ) {
            dbg("VirtualLockP", "Node: %u %u\n", 
                    call NeighborTable.getAddress(n), 
                    node_locks[n].status);
        }
    }

#ifdef REAL_WORLD
    uint32_t sim_time_string() {
        return call RequestTimer.getNow();
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

    void dumpStateString() {
        printf("DEBUG (%d): ", TOS_NODE_ID);
        printf("LOCK_%ld_STATE", sim_time_string());
        switch (status) {
            case LOCK_STATUS_IDLE: {
                printf("_IDLE\n");
                break;
            }
            case LOCK_STATUS_WAIT_REQUEST: {
                printf("_WAITREQUEST\n");
                break;
            }
            case LOCK_STATUS_WAIT_DONE: {
                printf("_WAITDONE\n");
                break;
            }
            case LOCK_STATUS_TRY_EXPIRED: {
                printf("_TRYEXPIRED\n");
                break;
            }
            case LOCK_STATUS_HOLD: {
                printf("_HOLD\n");
                break;
            }
            case LOCK_STATUS_APP_WAIT: {
                printf("_APPWAIT\n");
                break;
            }
            default: {
                printf("_UNKNOWN\n");
                break;
            }
        }
        printfflush();
    }
#else
    void dumpEvalString(lock_packet_t *lockpkt, am_addr_t addr, bool isTx) {
        dbg("VirtualLockPEval", "LOCK_%s_", sim_time_string());
        switch (lockpkt->msgtype) {
            case LOCK_MSG_REQUEST: {
                dbg_clear("VirtualLockPEval", "REQUEST_");
                break;
            }
            case LOCK_MSG_CONFLICT: {
                dbg_clear("VirtualLockPEval", "CONFLICT_");
                break;
            }
            case LOCK_MSG_DONE: {
                dbg_clear("VirtualLockPEval", "DONE_");
                break;
            }
            case LOCK_MSG_HOLD: {
                dbg_clear("VirtualLockPEval", "HOLD_");
                break;
            }
            default: {
                dbg_clear("VirtualLockPEval", "UNKNOWN_");
                break;
            }
        }
        // The ultimate destination determines whether this is BCAST or
        // 1-to-1
        if ( isTx ) {
            dbg_clear("VirtualLockPEval", "TX_%u\n", lockpkt->destAddr);
        } else {
            dbg_clear("VirtualLockPEval", "RX_%u_%u\n", 
                    lockpkt->destAddr, lockpkt->srcAddr);
        }
    }

    void dumpSyncString(lock_packet_t *lockpkt, am_addr_t addr, bool isTx) {
        if ( isTx ) {
            dbg("SynchronizePEval", "TX_%s_", sim_time_string());
        } else {
            dbg("SynchronizePEval", "RX_%s_", sim_time_string());
        }
        dbg_clear("SynchronizePEval", "%lu_%lu",
                call RequestTimer.getNow(),
                total_trans);
        if ( isTx ) {
            dbg_clear("SynchronizePEval", "\n");
        } else {
            if ( lockpkt != NULL ) {
                dbg_clear("SynchronizePEval", "_%u_%u\n", 
                        lockpkt->destAddr, lockpkt->srcAddr);
            } else {
                dbg_clear("SynchronizePEval", "_%u_%u\n", 
                        TOS_NODE_ID, addr);
            }
        }
    }

    void dumpStateString() {
        dbg("VirtualLockPEval", "LOCK_%s_STATE", sim_time_string());
        switch (status) {
            case LOCK_STATUS_IDLE: {
                dbg_clear("VirtualLockPEval", "_IDLE\n");
                break;
            }
            case LOCK_STATUS_WAIT_REQUEST: {
                dbg_clear("VirtualLockPEval", "_WAITREQUEST\n");
                break;
            }
            case LOCK_STATUS_WAIT_DONE: {
                dbg_clear("VirtualLockPEval", "_WAITDONE\n");
                break;
            }
            case LOCK_STATUS_TRY_EXPIRED: {
                dbg_clear("VirtualLockPEval", "_TRYEXPIRED\n");
                break;
            }
            case LOCK_STATUS_HOLD: {
                dbg_clear("VirtualLockPEval", "_HOLD\n");
                break;
            }
            case LOCK_STATUS_APP_WAIT: {
                dbg_clear("VirtualLockPEval", "_APPWAIT\n");
                break;
            }
            default: {
                dbg_clear("VirtualLockPEval", "_UNKNOWN\n");
                break;
            }
        }
    }
#endif

    void setState(int8_t st) {
        status = st;
        dumpStateString();
    }

    void resetParameters() {
        status = LOCK_STATUS_IDLE;
        ext_holdtime = 0;
        current_rt = 0;
        current_msgcount = 0;
        holdfactor = DEFAULT_HOLD_FACTOR;
        requestInitTime = 0;
        req_tries = 0;
    }

    void clearLockState() {
        // Clear node and locks table.
        memset(node_locks, 0, (NEIGHBOR_TABLE_SIZE+1)*sizeof(lock_t));
        node_locks[self].status = LOCK_NODE_IDLE;
        resetParameters();
    }

    void startTryTimer() {
        uint16_t num_neighbors = call NeighborTable.size();
        uint32_t retry_time = (num_neighbors/2 + 1) * node_locks[self].holdtime;
        call TryTimer.startOneShot(retry_time);
    }

    void startRequestTimer() {
        uint16_t num_neighbors = call NeighborTable.size();
        uint32_t retry_time = (num_neighbors/2 + 1) * node_locks[self].holdtime;
        if ( random_enable && node_locks[self].holdtime ) {
            retry_time += (call Random.rand32() %
                          (2*node_locks[self].holdtime));
        }
        call RequestTimer.startOneShot(retry_time);
    }

    int8_t getNodeLockStatus(int8_t idx) {
        lock_t* l = &node_locks[idx];
        return l->status;
    }

    void updateLockEntry(int8_t idx, lock_packet_t *lockpkt, int8_t st) {
        lock_t* l = &node_locks[idx];
        l->status = st;
        if ( lockpkt != NULL ) {
            l->lastseq = lockpkt->seq;
            l->metric = lockpkt->metric;
            l->holdtime = lockpkt->holdtime;
        }
    }

    void updateCurrentRT() {
        uint32_t now = call RequestTimer.getNow();
        current_rt = now - requestInitTime;
        dbg("VirtualLockP",
                "RT: now: %u init: %u rt: %u.\n", 
                now, requestInitTime, current_rt);
    }

    bool requestsExist(uint32_t* max_holdtime) {
        int8_t n;
        bool exist = FALSE;
        if ( max_holdtime != NULL ) {
            *max_holdtime = 0;
        }
        for ( n=call NeighborTable.getFirst(); 
              n!=-1; n=call NeighborTable.getNext() ) {
            lock_t *l = &node_locks[n];
            if ( (l->status & LOCK_NODE_RX_REQUEST) > 0 ) {
                exist = TRUE;
                if ( max_holdtime != NULL ) {
                    *max_holdtime = *max_holdtime + l->holdtime;
                }
            }
        }
        return exist;
    }

    bool lowerPriorityExists() {
        int8_t n;
        for ( n=call NeighborTable.getFirst(); 
              n!=-1; n=call NeighborTable.getNext() ) {
            lock_t *l = &node_locks[n];
            if ( (l->status & LOCK_NODE_RX_REQUEST_LOW) > 0 ) {
                return TRUE;
            }
        }
        return FALSE;
    }

    bool allRepliesRcvd() {
        int8_t n;
        for ( n=call NeighborTable.getFirst(); 
              n!=-1; n=call NeighborTable.getNext() ) {
            lock_t *l = &node_locks[n];
            //if ( l->status != LOCK_NODE_IDLE ) {
            if ( !(l->status & LOCK_NODE_IDLE) ) {
                return FALSE;
            }
        }
        return TRUE;
    }

    /***********************************************************/
    /******************* Send Protocol Msgs ********************/

    error_t sendRequestMsg(am_addr_t addr) {
        lock_packet_t sndpkt;
        sndpkt.msgtype = LOCK_MSG_REQUEST;
        sndpkt.srcAddr = call Transport.address();
        sndpkt.destAddr = addr;
        sndpkt.seq = 0; /* filled later */
        // Send metric and holdtime parameters requested by
        // 'self'.
        sndpkt.metric = node_locks[self].metric;
        sndpkt.holdtime = node_locks[self].holdtime + ext_holdtime;
        return call Transport.send(&sndpkt, addr);
    }

    error_t sendHoldMsg(am_addr_t addr) {
        lock_packet_t sndpkt;
        sndpkt.msgtype = LOCK_MSG_HOLD;
        sndpkt.srcAddr = call Transport.address();
        sndpkt.destAddr = addr;
        sndpkt.seq = 0; /* filled later */
        // Send metric and holdtime parameters requested by
        // 'self'.
        sndpkt.metric = node_locks[self].metric;
        sndpkt.holdtime = node_locks[self].holdtime;
        return call Transport.send(&sndpkt, addr); 
    }

    error_t sendDoneMsg(am_addr_t addr, bool clean) {
        lock_packet_t sndpkt;
        sndpkt.msgtype = LOCK_MSG_DONE;
        sndpkt.srcAddr = call Transport.address();
        sndpkt.destAddr = addr;
        sndpkt.seq = 0; /* filled later */
        // Send metric and holdtime parameters requested by
        // 'self'.
        //sndpkt.metric = node_locks[self].metric;
        if ( !clean ) {
            // Conditional REPLY.
            sndpkt.metric = 1;
        } else {
            sndpkt.metric = 0;
        }
        sndpkt.holdtime = node_locks[self].holdtime;
        dumpSyncString(NULL, addr, TRUE);
        return call Transport.send(&sndpkt, addr);
    }

    void sendHoldToNbrs(bool isFirst) {
        int8_t n;
        for ( n=call NeighborTable.getFirst(); 
                n!=-1; n=call NeighborTable.getNext() ) {
            am_addr_t ll_addr = call NeighborTable.getAddress(n);
            if ( getNodeLockStatus(n) &
                        (LOCK_NODE_TX_REQUEST|LOCK_NODE_RX_REQUEST|LOCK_NODE_RX_REQUEST_LOW) ) {
                // Send HOLD to only those neighbors that have outstanding
                // requests
                sendHoldMsg(ll_addr);
                if ( isFirst ) {
                    dumpSyncString(NULL, ll_addr, TRUE);
                }
            }
        }
    }

#ifdef USE_BROADCAST
    void sendRequestToNbrs() {
        int8_t n;
        // Send REQ to all neighbors.
        for ( n=call NeighborTable.getFirst(); 
              n!=-1; n=call NeighborTable.getNext() ) {
            lock_t *l = &node_locks[n];
            // Mark request sent to this nbr.
            l->status |= LOCK_NODE_TX_REQUEST;
            // Unset its IDLE status.
            l->status &= ~LOCK_NODE_IDLE;
        }
        sendRequestMsg(AM_BROADCAST_ADDR);
        dumpSyncString(NULL, AM_BROADCAST_ADDR, TRUE);
    }

    void sendDoneToNbrs() {
        sendDoneMsg(AM_BROADCAST_ADDR, TRUE);
    }
#else
    void sendRequestToNbrs() {
        int8_t n;
        // Send REQ to all neighbors.
        for ( n=call NeighborTable.getFirst(); 
              n!=-1; n=call NeighborTable.getNext() ) {
            lock_t *l = &node_locks[n];
            am_addr_t ll_addr = call NeighborTable.getAddress(n);
            // Mark request sent to this nbr.
            l->status |= LOCK_NODE_TX_REQUEST;
            // Unset its IDLE status.
            l->status &= ~LOCK_NODE_IDLE;
            sendRequestMsg(ll_addr);
            dumpSyncString(NULL, ll_addr, TRUE);
        }
    }

    void sendDoneToNbrs() {
        int8_t n;
        // Send REPLY to all neighbors.
        for ( n=call NeighborTable.getFirst(); 
              n!=-1; n=call NeighborTable.getNext() ) {
            am_addr_t ll_addr = call NeighborTable.getAddress(n);
            sendDoneMsg(ll_addr, TRUE);
        }
    }
#endif

    /************************************************************/

    void goToHoldState() {
        setState(LOCK_STATUS_HOLD);
        ext_holdtime = 0;
        call RequestTimer.stop();
        // Start the app wait timer
        call AppWaitTimer.startOneShot(app_wait_period);
    }

    void doClearRequest() {
        // Purge the lock packet queue.
        call Transport.clearAll();
        // Send DONE message to all nodes so that they can go
        // ahead and get the locks.
        sendDoneToNbrs();
        // Reset request parameters
        resetParameters();
    }

    void neighborAddedTask(int8_t idx) {
        am_addr_t ll_addr = call NeighborTable.getAddress(idx);
        lock_t* l = &node_locks[idx];
        switch (status) {
            case LOCK_STATUS_WAIT_REQUEST: 
            {
                l->status |= LOCK_NODE_TX_REQUEST;
                l->status &= ~LOCK_NODE_IDLE;
                // Send request msg to node
                sendRequestMsg(ll_addr);
                // Restart the request timer
                call RequestTimer.stop();
                startRequestTimer();
                break;
            }
            default: break;
        }
    }

    void neighborRemovedTask() {
        // This is equivalent to receving a REPLY from the removed
        // node.
        switch (status) {
            case LOCK_STATUS_WAIT_REQUEST: 
            {
                if ( allRepliesRcvd() ) {
                    // All neighbors have given permission.
                    goToHoldState();
                }
                break;
            }
            case LOCK_STATUS_WAIT_DONE: 
            {
                if ( allRepliesRcvd() ) {
                    // All neighbors are done.
                    uint32_t dtfire = (call Random.rand32() % (1024L)) + 30;
                    //call TryTimer.stop();
                    // Send REQUESTS after some random time.
                    call SendTimer.startOneShot(dtfire);
                }
                break;
            }
            default: break;
        }
    }

    /*************** Process Rcvd Protocol Msgs ***************/

    void initLockRequest(lock_packet_t *lockpkt) {
        // Update lock request status.
        updateLockEntry(self, lockpkt, LOCK_NODE_RX_REQUEST);
        // Start counting response time
        requestInitTime = call RequestTimer.getNow();
        if ( call NeighborTable.isEmpty() ) {
            // There are no interfering neighbors.
            // Grab the lock.
            goToHoldState();
            return;
        }
#if 0
        // XXX
        if ( requestsExist(&ext_holdtime) ) {
            // Some neighbors have already requested locks.
            if ( random_enable ) {
                // Random sequence. Dont send request to all neighbors yet.
                // Send HOLD msg to check their status.
                sendHoldToNbrs(TRUE);
                // Start Try Timer.
                startTryTimer();
                // Go to next state and wait for REPLY messages from
                // all requesting neighbors.
                setState(LOCK_STATUS_WAIT_DONE);
                dumpNbrTable();
                return;
            }
            // Fall through in all other cases.
        }
#endif
        // Send request to all neighbors.
        sendRequestToNbrs();
        // Start with count 1 so that the node doesn't wait too much in this
        // state during random access.
        req_tries = 1;
        // Start the request timer.
        startRequestTimer();
        // Timer started. Set next state.
        setState(LOCK_STATUS_WAIT_REQUEST);
        dumpNbrTable();
    }

    error_t lockRequestRcvd(int8_t idx, lock_packet_t *lockpkt, am_addr_t srcAddr) {
        if ( (srcAddr==call Transport.address()) &&
                (status!=LOCK_STATUS_IDLE) ) {
            // This is a request from self. Already recorded.
            // Ignore it.
            dbg("VirtualLockPEval", "This should not happen.\n");
            dbg("VirtualLockP", "This should not happen.\n");
            return SUCCESS;
        }
        if ( srcAddr == call Transport.address() ) {
            dbg("VirtualLockP",
                    "Received REQUEST from SELF:\n");
        } else {
            dbg("VirtualLockP", 
                    "Received REQUEST from %u:\n", srcAddr);
        }
        dbg("VirtualLockP", "\t\tmetric: %u holdtime: %u\n",
                lockpkt->metric, lockpkt->holdtime);
        switch (status) {
            case LOCK_STATUS_IDLE: 
            {
                // Check if the request is from 'self'
                if ( srcAddr == call Transport.address() ) {
                    // This is a request from self.
                    // Initiate the lock requesting process.
                    dbg("VirtualLockPEval", "##_%s_Received SELF request.\n",
                            sim_time_string());
                    initLockRequest(lockpkt);
                    return SUCCESS;
                }
                // Unset any old lower priority requests from this neighbor
                updateLockEntry(idx, lockpkt, 
                        getNodeLockStatus(idx)&~LOCK_NODE_RX_REQUEST_LOW);
                // If code reaches here, the request is from some neighboring node
                updateLockEntry(idx, lockpkt, 
                        getNodeLockStatus(idx)|LOCK_NODE_RX_REQUEST);
                // Send a REPLY to this node.
                sendDoneMsg(srcAddr, TRUE);
                dumpNbrTable();
                // Signal the application and let it take desired action.
                signal VirtualLock.lockRequest(lockpkt->metric);
                return SUCCESS;
            }
            case LOCK_STATUS_WAIT_REQUEST: 
            {
                // Update current msg count
                current_msgcount++;
                if ( signal VirtualLock.checkNbrMetric(lockpkt->metric) ) {
                    // Neighbor has higher priority. 
                    // Unset any old lower priority requests from this
                    // neighbor, if they exist (just for safety here)
                    updateLockEntry(idx, lockpkt, 
                            getNodeLockStatus(idx)&~LOCK_NODE_RX_REQUEST_LOW);
                    // Update neighbor table entry for request source node
                    updateLockEntry(idx, lockpkt, 
                            getNodeLockStatus(idx)|LOCK_NODE_RX_REQUEST);
                    // Update my hold time depending on the new conflict msg
                    // (assumed) sent by the neighbor
                    requestsExist(&ext_holdtime);
                    if ( random_enable ) {
                        // Send it a conditional REPLY msg so that it records that
                        // this node has an outstanding low priority request.
                        sendDoneMsg(srcAddr, FALSE);
                    } else {
                        // In strict sequential mode, there is only one kind
                        // of REPLY.
                        sendDoneMsg(srcAddr, TRUE);
                    }
                    // Mark this node to wait for REPLY from this node.
                    updateLockEntry(idx, lockpkt, 
                            getNodeLockStatus(idx)|LOCK_NODE_TX_REQUEST);
                    updateLockEntry(idx, lockpkt, 
                            getNodeLockStatus(idx)&~LOCK_NODE_IDLE);
                    // Stop the request timer.
                    call RequestTimer.stop();
                    // Restart the request timer. period = [(c-1)*h/16, c*h/16]
                    startRequestTimer();
                    // Signal that there was a conflict from some neighbor.
                    signal VirtualLock.lockConflict();
                } else {
                    // Neighbor has low priority. Update its status in the
                    // table. Remove important request status.
                    updateLockEntry(idx, lockpkt, 
                            getNodeLockStatus(idx)&~LOCK_NODE_RX_REQUEST);
                    // Update low priority status.
                    updateLockEntry(idx, lockpkt, 
                            getNodeLockStatus(idx)|LOCK_NODE_RX_REQUEST_LOW);
                }
                dumpNbrTable();
                return SUCCESS;
            }
            case LOCK_STATUS_WAIT_DONE: 
            {
                // Only reach this state during relaxed access.
                // Some neighbor requesting lock.
                // Update status
                // Unset any old lower priority requests from this neighbor
                updateLockEntry(idx, lockpkt, 
                        getNodeLockStatus(idx)&~LOCK_NODE_RX_REQUEST_LOW);
                updateLockEntry(idx, lockpkt, 
                        getNodeLockStatus(idx)|LOCK_NODE_RX_REQUEST);
                // Update my hold time depending on the new conflict msg
                // sent by a neighbor
                requestsExist(&ext_holdtime);
                // Send a REPLY msg.
                sendDoneMsg(srcAddr, TRUE);
                // Update current msg count
                current_msgcount++;
                // Restart the try timer.
                //call TryTimer.stop();
                //startTryTimer();
                return SUCCESS;
            }
            case LOCK_STATUS_HOLD: 
            {
                // Some neighbor requesting lock.
                if ( signal VirtualLock.checkNbrMetric(lockpkt->metric) ) {
                    // Neighbor has higher priority. 
                    // Unset any old lower priority requests from this neighbor
                    updateLockEntry(idx, lockpkt, 
                            getNodeLockStatus(idx)&~LOCK_NODE_RX_REQUEST_LOW);
                    // Update status
                    updateLockEntry(idx, lockpkt, 
                            getNodeLockStatus(idx)|LOCK_NODE_RX_REQUEST);
                    signal VirtualLock.lockRequest(lockpkt->metric);
                } else {
                    // Unset any old lower priority requests from this neighbor
                    updateLockEntry(idx, lockpkt, 
                            getNodeLockStatus(idx)&~LOCK_NODE_RX_REQUEST);
                    // Update status
                    updateLockEntry(idx, lockpkt, 
                            getNodeLockStatus(idx)|LOCK_NODE_RX_REQUEST_LOW);
                }
                return SUCCESS;
            }
            default: break;
        }

        return SUCCESS;
    }

    error_t lockDoneRcvd(int8_t idx, lock_packet_t *lockpkt, am_addr_t srcAddr) {
        // Update neighbor table entry for source node
        if ( lockpkt->metric ) {
            // Conditional REPLY rcvd.
            // Remove any important request status
            updateLockEntry(idx, lockpkt, 
                    getNodeLockStatus(idx)&~LOCK_NODE_RX_REQUEST);
            // Record that this node has replied.
            updateLockEntry(idx, lockpkt, 
                    getNodeLockStatus(idx)&~LOCK_NODE_TX_REQUEST);
            // Record that this node has outstanding low priority request.
            updateLockEntry(idx, lockpkt, 
                    getNodeLockStatus(idx)|LOCK_NODE_RX_REQUEST_LOW);
            // Set the IDLE flag
            updateLockEntry(idx, lockpkt, 
                    getNodeLockStatus(idx)|LOCK_NODE_IDLE);
        } else {
            // Clean REPLY.
            updateLockEntry(idx, lockpkt, LOCK_NODE_IDLE);
        }
        // Update my hold time depending on the remaining requests
        //requestsExist(&ext_holdtime);
        switch (status) {
            case LOCK_STATUS_HOLD:
            case LOCK_STATUS_IDLE: {
                // Force treat the REPLY as clean
                updateLockEntry(idx, lockpkt, LOCK_NODE_IDLE);
                return SUCCESS;
            }
            case LOCK_STATUS_WAIT_REQUEST: 
            {
                // Update current msg count
                current_msgcount++;
                if ( allRepliesRcvd() ) {
                    // All neighbors have given permission.
                    goToHoldState();
                }
                return SUCCESS;
            }
            case LOCK_STATUS_WAIT_DONE: 
            {
                // Only reach this state in relaxed access.
                // Update current msg count
                current_msgcount++;
                if ( lockpkt->metric ) {
                    // Conditional REPLY received. This should not happen, but
                    // due to packet errors, you never know!
                    // So unset the IDLE status as the sender is still in its
                    // REQUEST state.
                    updateLockEntry(idx, lockpkt, 
                            getNodeLockStatus(idx)&~LOCK_NODE_IDLE);
                } else if ( allRepliesRcvd() ) {
                    // Clean REPLY rcvd. and All neighbors are done.
                    uint32_t dtfire = (call Random.rand32() % (256L)) + 30;
                    //call TryTimer.stop();
                    // Send REQUESTS after some random time.
                    call SendTimer.startOneShot(dtfire);
                }
                return SUCCESS;
            }
            default: break;
        }

        return SUCCESS;
    }

    error_t lockHoldRcvd(int8_t idx, lock_packet_t *lockpkt, am_addr_t srcAddr) {
        // Only received in relaxed access mode.
        // Update current msg count
        //updateLockEntry(idx, lockpkt, LOCK_NODE_IDLE);
        current_msgcount++;
        switch (status) {
            case LOCK_STATUS_IDLE: {
                // Treat the neighbor as IDLE. Update neighbor table entry for source node.
                updateLockEntry(idx, lockpkt, LOCK_NODE_IDLE);
                // Fall through to send a REPLY
                sendDoneMsg(srcAddr, TRUE);
                break;
            }
            case LOCK_STATUS_WAIT_DONE:
            {
                // The neighbor didnt receive the earlier REPLY msg.
                // Send it a REPLY msg again.
                sendDoneMsg(srcAddr, TRUE);
#if 0
                if ( allRepliesRcvd() ) {
                    // Clean REPLY rcvd. and All neighbors are done.
                    uint32_t dtfire = (call Random.rand32() % (256L)) + 30;
                    //call TryTimer.stop();
                    // Send REQUESTS after some random time.
                    call SendTimer.startOneShot(dtfire);
                }
#endif
                break;
            }
            case LOCK_STATUS_WAIT_REQUEST: 
            {
                // Treat this as a REPLY.
                // Update neighbor table entry for source node.
                updateLockEntry(idx, lockpkt, LOCK_NODE_IDLE);
                if ( allRepliesRcvd() ) {
                    // All neighbors have given permission.
                    goToHoldState();
                }
                break;
            }
            default: break;
        }

        return SUCCESS;
    }

    /**********************************************************/
    /************************ Tasks **************************/

    task void processRcvQueue() {
        lock_packet_t *lock_pkt = NULL;
        am_addr_t srcAddr = 0;
        int8_t idx = -1;

        if ( call RcvQueue.empty() ) return;
        
        // Get head of queue.
        atomic {
            lock_pkt = call RcvQueue.dequeue();
        }
        srcAddr = lock_pkt->srcAddr;

        if ( srcAddr != call Transport.address() ) {
            // Only do the following book-keeping if this msg is from a
            // neighbor.
            int16_t drop_pkt = call Random.rand16() % 100;
            lock_t *l = NULL;
            idx = call NeighborTable.getIndex(srcAddr);
            if ( idx < 0 ) {
                // The source is not an actuation neighbor of this node.
                // Ignore it.
                call RcvPool.put(lock_pkt);
                return;
            }
            if ( drop_pkt < PACKET_LOSS_RATE ) {
                // Drop the packet. PACKET_LOSS_RATE is always < 100.
                call RcvPool.put(lock_pkt);
                return;
            }
            // Get lock status of neighbor
            l = &node_locks[idx];
            dumpEvalString(lock_pkt, srcAddr, FALSE);
            if ( (l->rcvcnt != 0) && 
                 (l->lastseq >= lock_pkt->seq) ) {
                // Already seen this packet.
                call RcvPool.put(lock_pkt);
                return;
            }

            // New packet. Update counts and seq number
            l->rcvcnt++;
            l->lastseq = lock_pkt->seq;
            dumpSyncString(lock_pkt, srcAddr, FALSE);
        } else {
            dbg("VirtualLockPEval", "##_%s_Processing SELF request.\n",
                    sim_time_string());
        }
        
        switch (lock_pkt->msgtype) {
            case LOCK_MSG_REQUEST: {
                lockRequestRcvd(idx, lock_pkt, srcAddr);
                break;
            }
            case LOCK_MSG_DONE: {
                lockDoneRcvd(idx, lock_pkt, srcAddr);
                break;
            }
            case LOCK_MSG_HOLD: {
                lockHoldRcvd(idx, lock_pkt, srcAddr);
                break;
            }
            default: break;
        }
        call RcvPool.put(lock_pkt);

        post processRcvQueue();
    }
    
    task void processTryTimeout() {
        if (status == LOCK_STATUS_WAIT_DONE) { 
            if ( !allRepliesRcvd() ) {
                // Ping all neighbors that had sent requests.
                sendHoldToNbrs(FALSE);
                // Restart the try timer
                startTryTimer();
            }
        }
    }

    task void processRequestTimeout() {
        if ( status == LOCK_STATUS_WAIT_REQUEST ) {
            int8_t n = 0;
            req_tries++;
            if ( random_enable && (req_tries>MAX_TRIES_PIP)) {
                // Random sequence. Check if at least one lower priority and
                // at least one higher priority request exist.
                if ( requestsExist(NULL) && lowerPriorityExists() ) {
                    // Send HOLD msg to check their status.
                    sendHoldToNbrs(TRUE);
                    // Start Try Timer.
                    startTryTimer();
                    // Go to next state and wait for REPLY messages from
                    // all requesting neighbors.
                    setState(LOCK_STATUS_WAIT_DONE);
                    dumpNbrTable();
                    return;
                }
                // Fall through if reach here.
            }
            // Resend requests to nbrs that havent replied.
            for ( n=call NeighborTable.getFirst(); 
                    n!=-1; n=call NeighborTable.getNext() ) {
                am_addr_t ll_addr = call NeighborTable.getAddress(n);
                if ( getNodeLockStatus(n) & LOCK_NODE_TX_REQUEST ) {
                    sendRequestMsg(ll_addr);
                }
            }
            // Restart the request timer.
            startRequestTimer();
        }
    }

    task void processSendTimeout() {
        if ( status == LOCK_STATUS_WAIT_DONE ) {
            if ( allRepliesRcvd() ) {
                // Set next state.
                setState(LOCK_STATUS_WAIT_REQUEST);
                // Stop the try timer
                call TryTimer.stop();
                // Send request to all neighbors.
                sendRequestToNbrs();
                // Once the node goes to the WAIT state again, it must stay
                // there for a longer time that initially.
                req_tries = 0;
                // Start the request timer.
                startRequestTimer();
            } else {
                // Restart the try timer.
                if ( !call TryTimer.isRunning() ) {
                    startTryTimer();
                }
            }
        }
    }

    task void processAppWaitTimeout() {
        if ( status == LOCK_STATUS_HOLD ) {
            // Update and output current response time
            updateCurrentRT();
            // Signal grant to the application
            signal VirtualLock.lockGranted(LOCK_GRANT_NORMAL);
        }
    }

    /********** Public functions **********/

    command error_t VirtualLock.acquireLock(uint32_t hold_time) {
        am_addr_t self_addr = call Transport.address();
        // Simulate a local lock request pkt delivery
        lock_packet_t *lq = NULL;
        lock_packet_t lockpkt;
        atomic {
            lq = call RcvPool.get();
        }
        // Set necessary parameters.
        lockpkt.msgtype = LOCK_MSG_REQUEST;
        lockpkt.srcAddr = self_addr;
        lockpkt.destAddr = self_addr;
        lockpkt.metric = selfpriority;
        lockpkt.holdtime = hold_time;
        // Configure the transport layer.
        call Transport.setMaxRetries(2);
        call Transport.setRetryPeriod(64);
        if ( lq != NULL ) {
            // Successfully allocated space for new request.
            error_t ret = FAIL;
            memcpy(lq, &lockpkt, sizeof(lock_packet_t));
            atomic {
                ret = call RcvQueue.enqueue(lq);
            }
            if ( ret == SUCCESS ) {
                // Enqueued.
                post processRcvQueue();
                dbg("VirtualLockPEval", "##_%s_Posted SELF request.\n",
                        sim_time_string());
                return SUCCESS;
            } else {
                // Free up the space
                call RcvPool.put(lq);
            }
        }
        // If control reaches this point, something failed.
        // Force processing of request.
        dbg("VirtualLockPEval", "##_%s_Forcing SELF request.\n",
                sim_time_string());
        return lockRequestRcvd(-1, &lockpkt, self_addr);
    }

    command error_t VirtualLock.releaseLock() {
        if ( status == LOCK_STATUS_IDLE ) {
            // This node has not requested lock.
            // Ignore.
            return FAIL;
        }
        // Stop all the timers
        call RequestTimer.stop();
        call TryTimer.stop();
        call SendTimer.stop();
        call AppWaitTimer.stop();
        if ( status == LOCK_STATUS_HOLD ) {
            // Complete transaction. Update counts.
            total_trans++;
#ifdef REAL_WORLD
            printf("DEBUG (%d): ", TOS_NODE_ID);
            printf("LOCK_%ld_VIOLATIONS_%ld_%ld\n", 
                    sim_time_string(), total_trans, total_trans);
            printfflush();
#else
            dbg("VirtualLockPEval", "LOCK_%s_VIOLATIONS_%u_%u\n", 
                    sim_time_string(), total_trans, total_trans);
#endif
        }
        // Send done mesg and clear all state
        doClearRequest();
        return SUCCESS;
    }

    command void VirtualLock.setPriority(uint32_t priority) {
        selfpriority = priority;
    }

    command void VirtualLock.enableRandomAccess() {
        random_enable = TRUE;
    }

    command void VirtualLock.setWaitPeriod(uint32_t period) {
        if ( period > MIN_TIMER_PERIOD ) {
            app_wait_period = period;
        }
    }

    command void VirtualLock.setRequestPeriod(uint32_t period) {}

    command error_t Init.init() {
        selfpriority = TOS_NODE_ID;
        // last entry of locks table is this node itself.
        self = NEIGHBOR_TABLE_SIZE;
        app_wait_period = MIN_APP_WAIT_PERIOD;
        total_trans = 0;
        random_enable = FALSE;
        clearLockState();
        return SUCCESS;
    }

    event void TryTimer.fired() {
        switch (status) {
            case LOCK_STATUS_WAIT_DONE: 
            {
                post processTryTimeout();
                break;
            }
            default: break;
        }
    }

    event void RequestTimer.fired() {
        switch(status) {
            case LOCK_STATUS_WAIT_REQUEST: 
            {
                post processRequestTimeout();
                break;
            }
            default: break;
        }
    }

    event void SendTimer.fired() {
        switch(status) {
            case LOCK_STATUS_WAIT_DONE: 
            {
                post processSendTimeout();
                break;
            }
            default: break;
        }
    }

    event void AppWaitTimer.fired() {
        switch(status) {
            case LOCK_STATUS_HOLD: 
            {
                post processAppWaitTimeout();
                break;
            }
            default: break;
        }
    }

    event void NeighborTable.neighborAdded(int8_t idx) {
        // Initialize its lock state
        lock_t* l = &node_locks[idx];
        memset(l, 0, sizeof(lock_t));
        l->status = LOCK_NODE_IDLE;
        neighborAddedTask(idx);
    }

    event void NeighborTable.neighborRemoved(int8_t idx) {
        neighborRemovedTask();
    }

    event void Transport.sendDone(lock_packet_t *pkt, am_addr_t destAddr, error_t err) {
        // Update current msg count
        current_msgcount++;
        if ( err == FAIL ) {
            dbg("VirtualLockP", 
                    "Packet sent to node %u was not reliable. Msg type - %u\n", 
                    destAddr, pkt->msgtype);
        }
    }

    event lock_packet_t* Transport.receive(lock_packet_t* lock_pkt, am_addr_t srcAddr) {
        // Allocate space to put this pkt in queue
        error_t ret = FAIL;
        lock_packet_t *lq = NULL;
        atomic {
            lq = call RcvPool.get();
        }
        if ( lq == NULL ) return lock_pkt;

        // Copy contents from received msg
        memcpy(lq, lock_pkt, sizeof(lock_packet_t));

        atomic {
            ret = call RcvQueue.enqueue(lq);
        }
        if ( ret != SUCCESS ) {
            // No more space in the queue. Drop this packet.
            call RcvPool.put(lq);
            return lock_pkt;
        }

        // Post a task to process this msg.
        post processRcvQueue();
        return lock_pkt;
    }

}

