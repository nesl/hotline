
#ifdef REAL_WORLD
#include <printf.h>
#endif

#include "Neighbor.h"
#include "SharedVar.h"

#ifndef PACKET_LOSS_RATE
#define PACKET_LOSS_RATE    0
#endif

module ShareDataP {
    provides interface Init;
    provides interface SharedVariable;
    
    uses interface NeighborTable;
    
    uses interface VarTransport;
    uses interface Version;
    uses interface NbrTrickleTimer as UpdateTimer;

    uses interface Random;
}

implementation {

    typedef struct {
        bool synced;
        uint32_t seq;
        uint16_t mask;
    } msg_st_t;

    shared_vars_t n_vars[NEIGHBOR_TABLE_SIZE];
    shared_vars_t own_vars, copy_vars;
    msg_st_t n_msg[NEIGHBOR_TABLE_SIZE];
    uint8_t used[MAX_SHARED_VAR];
    uint8_t own_used[MAX_SHARED_VAR];
    bool dirty;     // Refers to the state of copy_vars
    bool reTx;

    command error_t Init.init() {
        memset(n_vars, 0, sizeof(shared_vars_t)*NEIGHBOR_TABLE_SIZE);
        memset(n_msg, 0, sizeof(msg_st_t)*NEIGHBOR_TABLE_SIZE);
        memset(&own_vars, 0, sizeof(shared_vars_t));
        memset(&copy_vars, 0, sizeof(shared_vars_t));
        memset(used, 0, sizeof(used));
        memset(own_used, 0, sizeof(own_used));
        dirty = FALSE;
        reTx = TRUE;
        return SUCCESS;
    }

    var_t* search_n(int8_t idx, uint8_t key) {
        uint8_t i = 0;
        if ( idx < 0 ) return NULL;
        for ( ; i<MAX_SHARED_VAR; i++ ) {
            if ( n_vars[idx].v[i].version == 0 ) continue;
            if ( n_vars[idx].v[i].key == key ) {
                return &n_vars[idx].v[i];
            }
        }
        return NULL;
    }

    var_t* find_empty_n(int8_t idx) {
        uint8_t i = 0;
        if ( idx < 0 ) return NULL;
        for ( ; i<MAX_SHARED_VAR; i++ ) {
            if ( n_vars[idx].v[i].version != 0 ) continue;
            // version == 0 means empty slot
            return &n_vars[idx].v[i];
        }
        return NULL;
    }

    var_t* search(uint8_t key) {
        uint8_t i = 0;
        for ( ; i<MAX_SHARED_VAR; i++ ) {
            if ( used[i] == 0 ) continue;   // Empty
            if ( copy_vars.v[i].key == key ) {
                return &copy_vars.v[i];
            }
        }
        return NULL;
    }

    var_t* find_empty() {
        uint8_t i = 0;
        for ( ; i<MAX_SHARED_VAR; i++ ) {
            if ( used[i] == 1 ) continue;
            used[i] = 1;
            return &copy_vars.v[i];
        }
        return NULL;
    }

    void mark_empty(var_t* v) {
        uint16_t i = 0;
        if ( v == NULL ) return;
        i = (uint8_t)(v - copy_vars.v);
        used[i] = 0;
        dbg("ShareDataPEval", "##_%s_Removing shared variable %u at index %u.\n", 
                sim_time_string(), v->key, i);
        v->key = 0;
        v->value = 0;
        v->version = 0;
    }

    command error_t SharedVariable.get(am_addr_t n, uint8_t key, float *value) {
        int8_t idx = call NeighborTable.getIndex(n);
        var_t *v = NULL;
        if ( idx < 0 ) {
            if ( n != TOS_NODE_ID ) return FAIL;
            // Need this node's variable
            v = search(key);
            // Fall through
        } else {
            // Need valid neighbor's variable
            v = search_n(idx, key);
        }
        if ( v == NULL ) return FAIL;
        *value = v->value;
        return SUCCESS;
    }

    command error_t SharedVariable.put(uint8_t key, float value) {
        var_t *v = search(key);
        if ( v == NULL ) {
            v = find_empty();
            if ( v == NULL ) {
                // Can not allocate.
                return FAIL;
            }
            v->key = key;
        }
        v->value = value;
        v->version = call Version.getNew(v->version);
        dirty = TRUE;
        return SUCCESS;
    }

    command error_t SharedVariable.remove(uint8_t key) {
        // TODO: This is a hacked implementation as the mirrored values at neighbors
        // are not removed. It just acts to reduce the size of SVR messages
        // transmitted following the call to remove().
        var_t *v = search(key);
        if ( v != NULL ) {
            mark_empty(v);
            dirty = TRUE;
        }
        return SUCCESS;
    }

    command void SharedVariable.flush() {
        if ( dirty ) {
            dirty = FALSE;
            memcpy(&own_vars, &copy_vars, sizeof(shared_vars_t));
            memcpy(own_used, used, sizeof(used));
            // Will try to Tx this update for the first time.
            reTx = FALSE;
            if ( call VarTransport.send(&own_vars, own_used, reTx) == SUCCESS ) {
                // Next transmissions of this update are repeats.
                reTx = TRUE;
            }
            // Reset the timer irrespective of send status
            call UpdateTimer.reset();
        }
    }

    command bool SharedVariable.isConsistent(am_addr_t n) {
        int8_t idx = call NeighborTable.getIndex(n);
        if ( idx < 0 ) return FALSE;
        return n_msg[idx].synced;
    }

    event bool UpdateTimer.fired() {
        if ( call VarTransport.send(&own_vars, own_used, reTx) == SUCCESS ) {
            if ( !reTx ) {
                // This was the first successful Tx of this update.
                // Next transmissions of this update are repeats.
                reTx = TRUE;
            }
            // Send again after a bigger period.
            return TRUE;
        }
        // Send again at the same period as the send command failed
        return FALSE;
    }

    event void VarTransport.receive(am_addr_t src, var_t *vars, 
            uint8_t num_vars, uint32_t seq, uint16_t mmask, uint16_t pmask) {
        uint8_t i;
        int8_t n = call NeighborTable.getIndex(src);
        int16_t drop_pkt = call Random.rand16() % 100;

        if ( n < 0 ) return;
        // Drop the packet randomly to simulate loss. PACKET_LOSS_RATE is always < 100.
        if ( drop_pkt < PACKET_LOSS_RATE ) return;

        // Update data synchronization status
        if ( seq > n_msg[n].seq ) {
            // New update. Reset the state machine.
            n_msg[n].seq = seq;
            n_msg[n].synced = FALSE;
            n_msg[n].mask = mmask;
        }
        dbg("ShareDataP", "##_%s_Rcvd: Frm - %u Seq - %u Mask - 0x%x Pmask - 0x%x\n",
                sim_time_string(), src, seq, n_msg[n].mask, pmask);
        dbg("ShareDataPEval", "SVR_%s_RX_%u_%u_%u_OF_%u\n",
                sim_time_string(), src, seq, pmask, mmask);
        
        // Do not process old packets to save processing time
        if (n_msg[n].synced) return;

        for ( i=0; i<num_vars; i++ ) {
            // Find the entry corresponding to vars[i] in n_vars[n]
            var_t *nv = search_n(n, vars[i].key);
            if ( nv == NULL ) {
                // Entry does not exist. Create new entry.
                nv = find_empty_n(n);
                if ( nv == NULL ) {
                    // No more space in neighbor table. Discard.
                    continue;
                }
            }
            if ( call Version.changed(nv->version,
                                      vars[i].version) ) {
                // Shared variable has changed.
                nv->key = vars[i].key;
                nv->version = vars[i].version;
                nv->value = vars[i].value;
                dbg("ShareDataP", "##_%s_Rcvd: Frm - %u Key - %u Value - %f Version - %lu\n",
                        sim_time_string(), src, vars[i].key, vars[i].value, vars[i].version);
                signal SharedVariable.changed(src, nv->key, nv->version);
            }
        }
        // Update stored mask with this pkt bit
        n_msg[n].mask &= ~pmask;
        if ( n_msg[n].mask == 0 ) {
            // All pkts for this update received.
            if ( !n_msg[n].synced ) {
                // It just rcvd all packets for this update
                n_msg[n].synced = TRUE;
                signal SharedVariable.synced(src);
            }
        }
    }

    event void NeighborTable.neighborAdded(int8_t idx) {
        // Added this initialization.
        n_msg[idx].synced = TRUE;
        n_msg[idx].seq = 0;
    }
    
    event void NeighborTable.neighborRemoved(int8_t idx) {
        memset(&n_vars[idx], 0, sizeof(shared_vars_t));
        memset(&n_msg[idx], 0, sizeof(msg_st_t));
    }

    default event void SharedVariable.changed(am_addr_t n,
            uint8_t key, uint32_t version) {}

    default event void SharedVariable.synced(am_addr_t n) {}
}
