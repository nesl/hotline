
#include "locks.h"

generic module SynchronizeStaticP(uint32_t MIN_ITER_PERIOD,
                                  uint32_t MAX_ITER_PERIOD) {
    provides interface Sync;
    provides interface VirtualLock;
    provides interface StdControl as Iterations;

    uses interface SharedVariable;
    uses interface NeighborTable;
    uses interface StdControl as NeighborDiscovery;
    uses interface Timer<TMilli> as StampTimer;

    uses interface DebugLog;
}
implementation {

#define EMPTY               0xFFFF

#define PRIORITY            254     // key for shared variable
#define ITERATION           255     // Key for shared variable

    uint16_t niter[NEIGHBOR_TABLE_SIZE];
    uint16_t npr[NEIGHBOR_TABLE_SIZE];
    uint16_t curr_iter;
    uint16_t self_pr;
    bool removed;

    uint32_t curr_period;

    enum {
        SYNC_IDLE   = 0,
        SYNC_LOCK,
        SYNC_LOCKED,
        SYNC_WAIT,
        SYNC_SYNCED,
    } st;

    void send_sync() {
        call DebugLog.print(curr_iter);
        call SharedVariable.put(ITERATION, (float)curr_iter); 
        call SharedVariable.flush();
        dbg("SynchronizeP", "##_%s_%u_TxSync\n",
                sim_time_string(),
                curr_iter);
        dbg("SynchronizePEval", "TX_%s_%lu_%u_TxSync\n",
                sim_time_string(),
                call StampTimer.getNow(),
                curr_iter);
    }

    bool locked() {
        int8_t n;
        for ( n=call NeighborTable.getFirst();
                n!=-1; n=call NeighborTable.getNext() ) {
            // First check if neighbor's priority is valid
            if ( npr[n] == EMPTY ) return FALSE;
            if ( npr[n] < self_pr ) {
                // Higher priority neighbor.
                // (Lower number is higher priority)
                if ( niter[n] < curr_iter ) return FALSE;
                if ( !call SharedVariable.isConsistent(call NeighborTable.getAddress(n)) ) return FALSE;
            }
        }
        return TRUE;
    }

    bool received_all() {
        int8_t n;
        for ( n=call NeighborTable.getFirst();
                n!=-1; n=call NeighborTable.getNext() ) {
            am_addr_t naddr = call NeighborTable.getAddress(n);
            if ( niter[n] < curr_iter ) return FALSE;
            if ( !call SharedVariable.isConsistent(naddr) ) return FALSE;
        }
        return TRUE;
    }

    void remove_pr() {
        int8_t n = -1;
        if ( removed ) return;
        for ( n=call NeighborTable.getFirst();
                n!=-1; n=call NeighborTable.getNext() ) {
            // First check if neighbor's priority is valid
            if ( npr[n] == EMPTY ) return;
        }
        // Received all neighbors' priorities
        call SharedVariable.remove(PRIORITY);
        removed = TRUE;
    }

    task void signal_locked() {
        dbg("SynchronizeP", "##_%s_%u_Locked\n",
                sim_time_string(),
                curr_iter);
        st = SYNC_LOCKED;
        signal VirtualLock.lockGranted(LOCK_GRANT_NORMAL);
    }

    task void signal_synced() {
        if ( st == SYNC_SYNCED ) {
            st = SYNC_IDLE;
            // PRIORITY variable is no longer required as all the neighbors
            // have recorded this node's priority.
            remove_pr();
            signal Sync.synced();
        }
    }

    void set_synced() {
        dbg("SynchronizeP", "##_%s_%u_Synced\n",
                sim_time_string(),
                curr_iter);
        st = SYNC_SYNCED;
        post signal_synced();
    }

    command error_t Iterations.start() {
        curr_period = 0;
        call StampTimer.stop();
        if ( (st==SYNC_WAIT) && 
             received_all() ) {
            set_synced();
        }
        return SUCCESS;
    }

    command error_t Iterations.stop() {
        if ( curr_period == 0 ) {
            // First call to stop.
            curr_period = MIN_ITER_PERIOD;
        } else if ( curr_period < MAX_ITER_PERIOD) {
            // Increase the iteration period.
            curr_period <<= 1;
        }
        return SUCCESS;
    }

    command void Sync.init() {
        memset(niter, 0, sizeof(niter));
        memset(npr, 0xFF, sizeof(npr));
        curr_iter = 0;
        st = SYNC_IDLE;
        self_pr = TOS_NODE_ID;
        curr_period = 0;
        removed = FALSE;
        call NeighborDiscovery.start();
    }

    command error_t VirtualLock.acquireLock(uint32_t holdtime) {
        if ( st != SYNC_IDLE ) return FAIL;
        st = SYNC_LOCK;
        curr_iter++;
        if ( locked() ) {
            post signal_locked();
        }
        return SUCCESS;
    }

    command error_t VirtualLock.releaseLock() {
        if ( st == SYNC_LOCKED ) {
            st = SYNC_IDLE;
            send_sync();
        }
        return SUCCESS;
    }

    command void Sync.sync() {
        if ( st == SYNC_IDLE ) {
            st = SYNC_WAIT;
            if ( curr_period > 0 ) {
                // Delay sync by at least curr_period.
                call StampTimer.startOneShot(curr_period);
            }
        }
        if ( (st==SYNC_WAIT) && 
             (!call StampTimer.isRunning()) &&
             received_all() ) {
            set_synced();
        }
    }

    command void Sync.cancel() {
        if ( st == SYNC_WAIT ) {
            st = SYNC_IDLE;
            call StampTimer.stop();
        }
    }

    command void VirtualLock.setPriority(uint32_t priority) {
        self_pr = (uint16_t)priority;
        call SharedVariable.put(PRIORITY, (float)self_pr); 
        call SharedVariable.flush();
        dbg("SynchronizeP", "##_%s_%u_TxPriority\n",
                sim_time_string(),
                self_pr);
    }

    event void SharedVariable.changed(am_addr_t n, uint8_t key, uint32_t version) {
        if ( key == PRIORITY ) {
            int8_t idx = -1;
            float v;
            idx = call NeighborTable.getIndex(n);
            call SharedVariable.get(n, PRIORITY, &v);
            npr[idx] = (uint16_t)v;
            dbg("SynchronizeP", "##_%s_%u_%u_RxPriority\n",
                    sim_time_string(), n,
                    npr[idx]);
        } 
        if ( key == ITERATION ) {
            // Iteration update.
            // Mark the neighbor's iteration number
            int8_t idx = -1;
            float v;
            idx = call NeighborTable.getIndex(n);
            call SharedVariable.get(n, ITERATION, &v);
            niter[idx] = (uint16_t)v;
            dbg("SynchronizeP", "##_%s_%u_%u_RxSync\n",
                    sim_time_string(), n,
                    niter[idx]);
            dbg("SynchronizePEval", "RX_%s_%lu_%u_%u_%u_RxSync\n",
                    sim_time_string(),
                    call StampTimer.getNow(),
                    niter[idx],
                    TOS_NODE_ID,
                    n);
        }
    }

    event void SharedVariable.synced(am_addr_t n) {
        // Check if estimates of all actuators have been received
        // This is triggered even when a non-iteration update is received to
        // make sure that the synced event is signalled only when the caches
        // are also synchronized.
        if ( (st==SYNC_WAIT) && 
             (!call StampTimer.isRunning()) &&
             received_all() ) {
            set_synced();
        } else if ( (st==SYNC_LOCK) && locked() ) {
            post signal_locked();
        }
    }

    event void StampTimer.fired() {
        if ( (st==SYNC_WAIT) && received_all() ) {
            // Sync period finished and all neighbors have
            // synchronized already.
            set_synced();
        }
    }

    event void NeighborTable.neighborAdded(int8_t idx) {}
    event void NeighborTable.neighborRemoved(int8_t idx) {
        niter[idx] = 0;
        npr[idx] = EMPTY;
    }

    command void VirtualLock.enableRandomAccess() {}
    command void VirtualLock.setWaitPeriod(uint32_t period) {}
    command void VirtualLock.setRequestPeriod(uint32_t period) {}

    default event bool VirtualLock.checkNbrMetric(uint32_t metric) { 
        return TRUE;
    }
    default event void VirtualLock.lockRequest(uint32_t metric) {}
    default event void VirtualLock.lockViolation(uint32_t metric) {}
    default event void VirtualLock.lockConflict() {}
}

