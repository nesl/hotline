
module SynchronizeP {
    provides interface Sync;
    provides interface StdControl as Iterations;

    uses interface SharedVariable;
    uses interface NeighborTable;
    uses interface StdControl as NeighborDiscovery;
    uses interface Timer<TMilli> as StampTimer;

    uses interface DebugLog;
}
implementation {

#define ITERATION           255     // Key for shared variable

    uint16_t niter[NEIGHBOR_TABLE_SIZE];
    uint16_t curr_iter;
    bool started;
    
    enum {
        SYNC_IDLE   = 0,
        SYNC_WAIT,
        SYNC_SYNCED,
    } st;

    void send_sync() {
        // First tell application to print current estimates.
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

    task void do_send_sync() {
        send_sync();
    }

    task void signal_synced() {
        if ( st == SYNC_SYNCED ) {
            st = SYNC_IDLE;
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
        started = TRUE;
        return SUCCESS;
    }

    command error_t Iterations.stop() {
        int8_t n;
        uint16_t saved_iter = curr_iter;
        started = FALSE;
        // Send a SYNC message to neighbor(s) waiting for this node by
        // incrementing the curr_iter count to the max of all neighbors.
        for ( n=call NeighborTable.getFirst();
                n!=-1; n=call NeighborTable.getNext() ) {
            if ( niter[n] > curr_iter ) {
                curr_iter = niter[n];
            }
        }
        if ( curr_iter > saved_iter ) {
            post do_send_sync();
        }
        return SUCCESS;
    }

    command void Sync.init() {
        memset(niter, 0, sizeof(niter));
        curr_iter = 0;
        st = SYNC_IDLE;
        started = TRUE;
        call NeighborDiscovery.start();
    }

    command void Sync.sync() {
        if ( !started ) return;
        if ( st == SYNC_IDLE ) {
            st = SYNC_WAIT;
            curr_iter++;
            send_sync();
        }
        if ( (st==SYNC_WAIT) && received_all() ) {
            set_synced();
        }
    }

    command void Sync.cancel() {
        st = SYNC_IDLE;
    }

    event void SharedVariable.changed(am_addr_t n, uint8_t key, uint32_t version) {
        int8_t idx = -1;
        float v;

        if ( key == ITERATION ) {
            // Iteration update.
            // Mark the neighbor's iteration number
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
            //if ( !started ) {
                // The application is not iterating.
                // Send a dummy response if required.
            //    if ( niter[idx] > curr_iter ) {
            //        curr_iter = niter[idx];
            //        post do_send_sync();
            //    }
            //}
        }
        //if ( started && (st==SYNC_WAIT) && received_all() ) {
        //    set_synced();
        //}
    }

    event void SharedVariable.synced(am_addr_t n) {
        if ( started ) {
            // Check if estimates of all actuators have been received
            // This is triggered even when a non-iteration update is received to
            // make sure that the synced event is signalled only when the caches
            // are also synchronized.
            if ( (st==SYNC_WAIT) && received_all() ) {
                set_synced();
            }
        } else {
            // The application is not iterating.
            // Send a dummy response if required.
            int8_t idx = call NeighborTable.getIndex(n);
            if ( niter[idx] > curr_iter ) {
                curr_iter = niter[idx];
                post do_send_sync();
            }
        }
    }

    event void StampTimer.fired() {}
    event void NeighborTable.neighborAdded(int8_t idx) {}
    event void NeighborTable.neighborRemoved(int8_t idx) {
        niter[idx] = 0;
    }

}

