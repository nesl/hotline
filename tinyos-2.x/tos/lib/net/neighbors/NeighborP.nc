
#ifdef REAL_WORLD
#include <printf.h>
#endif
#include "Neighbor.h"

module NeighborP {
    provides interface StdControl;
    provides interface Init;
    provides interface NeighborTable[uint8_t id];
    
    uses interface Zone;

    uses interface Queue<am_addr_t> as ZoneChangeQueue;

    uses interface Timer<TMilli> as StampTimer;
}

implementation {

#define INVALID_ADDR    AM_BROADCAST_ADDR

    bool start_disc = FALSE;
    neighbor_t neighbor_table[NEIGHBOR_TABLE_SIZE];
    int8_t start[UQCOUNT_NBRTABLE];
    uint16_t size;

    /********** Private functions **********/

    void neighbor_removed(int8_t idx) {
        uint8_t id;
        for (id=0; id<UQCOUNT_NBRTABLE; id++) {
            signal NeighborTable.neighborRemoved[id](idx);
        }
    }

    void neighbor_added(int8_t idx) {
        uint8_t id;
        for (id=0; id<UQCOUNT_NBRTABLE; id++) {
            signal NeighborTable.neighborAdded[id](idx);
        }
    }

    int8_t findIndex(neighbor_t* table, am_addr_t srcAddr) {
        int8_t idx;
        if ( table == NULL ) {
            table = neighbor_table;
        }
        for ( idx = 0; idx < NEIGHBOR_TABLE_SIZE; idx++ ) {
            if ( table[idx].flags & INUSE_ENTRY ) {
                if ( table[idx].ll_addr == srcAddr ) {
                    return idx;
                }
            }
        }

        return -1;
    }

    int8_t findEmptyIndex() {
        int8_t idx;
        for ( idx = 0; idx < NEIGHBOR_TABLE_SIZE; idx++ ) {
            if ( neighbor_table[idx].flags & INUSE_ENTRY ) continue;
            return idx;
        }

        return -1;
    }

    void insertNbr(int8_t idx, am_addr_t srcAddr) {
        neighbor_t *n = &neighbor_table[idx];
        n->ll_addr = srcAddr;
        // flags to describe the state of this entry
        n->flags = INUSE_ENTRY;
        size++;
    }

    void removeNbr(int8_t idx) {
        neighbor_table[idx].flags &= ~(INUSE_ENTRY);
        size--;
    }

    void filterNbrTable() {
        int8_t idx;
        for ( idx = 0; idx < NEIGHBOR_TABLE_SIZE; idx++ ) {
            if ( neighbor_table[idx].flags & INUSE_ENTRY ) {
                if ( !call Zone.intersects(neighbor_table[idx].ll_addr) ) {
                    // This is not a valid neighbor anymore. Remove it.
                    removeNbr(idx);
                    neighbor_removed(idx);
                }
            }
        }
    }

    bool empty() {
        return (size == 0);
    }

    neighbor_t* getNextNbr(neighbor_t* table, 
                           int8_t *start_idx) {
        for ( ; *start_idx < NEIGHBOR_TABLE_SIZE; (*start_idx)++) {
            if ( table[*start_idx].flags & INUSE_ENTRY ) {
                (*start_idx)++;
                return &table[(*start_idx)-1];
            }
        }

        return NULL;
    }

#ifdef REAL_WORLD
    uint32_t sim_time_string() {
        return call StampTimer.getNow();
    }

    task void dumpNbrTable() {
        int8_t idx;
        dbg("NeighborP",
            "Neighbor Table--\n");
        printf("DEBUG (%d): ", TOS_NODE_ID);
        printf("NEIGHBOR_%ld_TABLE", sim_time_string());
        for ( idx = 0; idx < NEIGHBOR_TABLE_SIZE; idx++ ) {
            if ( neighbor_table[idx].flags & INUSE_ENTRY ) {
                dbg("NeighborP",
                    "Neighbor: %u\n", neighbor_table[idx].ll_addr);
                printf("_%u", neighbor_table[idx].ll_addr);
            }
        }
        printf("\n");
        printfflush();
    }
#else
    task void dumpNbrTable() {
        int8_t idx;
        dbg("NeighborP",
            "Neighbor Table--\n");
        dbg("NeighborPEval",
            "NEIGHBOR_%s_TABLE", sim_time_string());
        for ( idx = 0; idx < NEIGHBOR_TABLE_SIZE; idx++ ) {
            if ( neighbor_table[idx].flags & INUSE_ENTRY ) {
                dbg("NeighborP",
                    "Neighbor: %u\n", neighbor_table[idx].ll_addr);
                dbg_clear("NeighborPEval",
                    "_%u", neighbor_table[idx].ll_addr);
            }
        }
        dbg_clear("NeighborPEval", "\n");
    }
#endif

    task void processZoneChange() {
        // Zone of some other node changed.
        int8_t idx = 0;
        am_addr_t node = 0;
        if ( call ZoneChangeQueue.empty() ) return;
        
        // Get node at head of queue.
        node = call ZoneChangeQueue.dequeue();
        // Check if this node is in the neighbor table. 
        idx = findIndex(NULL, node);
        dbg("NeighborP",
                "Node %u changed its zone.\n", node);
        if ( !call Zone.intersects(node) ) {
            // Neighbor's zone does not overlap with this node.
            // Remove it from the neighbor table if it exists.
            if ( idx >= 0 ) {
                removeNbr(idx);
                neighbor_removed(idx);
            }
            // Ignore it.
        } else {
            // Found a neighbor with overlapping zone.
            if ( idx < 0 ) {
                // Neighbor entry does not exist. Create a new one.
                idx = findEmptyIndex();
                if ( idx < 0 ) return;
                insertNbr(idx, node);
                neighbor_added(idx);
            }
        }
        // Dump the neighbor table for debug purposes
        post dumpNbrTable();
        post processZoneChange();
    }

    /********** Public functions **********/

    command error_t Init.init() {
        start_disc = FALSE;
        size = 0;
        memset(neighbor_table, 0, NEIGHBOR_TABLE_SIZE*sizeof(neighbor_t));
        memset(start, 0, UQCOUNT_NBRTABLE*sizeof(int8_t));
        return SUCCESS;
    }

    command error_t StdControl.start() {
        if ( start_disc ) return SUCCESS;
        start_disc = TRUE;
        return call Zone.enable();
    }

    command error_t StdControl.stop() {
        if ( start_disc ) {
            start_disc = FALSE;
            return call Zone.disable();
        }
        return SUCCESS;
    }

    command bool NeighborTable.isEmpty[uint8_t id]() {
        return empty();
    }

    command uint16_t NeighborTable.size[uint8_t id]() {
        return size;
    }

    command bool NeighborTable.exists[uint8_t id](am_addr_t addr) {
        return (findIndex(neighbor_table, addr) >= 0);
    }

    command int8_t NeighborTable.getIndex[uint8_t id](am_addr_t addr) {
        return findIndex(neighbor_table, addr);
    }

    command am_addr_t NeighborTable.getAddress[uint8_t id](int8_t idx) {
        if ( idx < NEIGHBOR_TABLE_SIZE ) {
            if ( neighbor_table[idx].flags & INUSE_ENTRY ) {
                return neighbor_table[idx].ll_addr;
            }
        }
        return INVALID_ADDR;
    }

    command int8_t NeighborTable.getFirst[uint8_t id]() {
        neighbor_t *n;
        start[id] = 0;
        n = getNextNbr(neighbor_table, &start[id]);
        if ( n != NULL ) {
            return start[id]-1;
        }
        return -1;
    }

    command int8_t NeighborTable.getNext[uint8_t id]() {
        neighbor_t *n = getNextNbr(neighbor_table, &start[id]);
        if ( n != NULL ) {
            return start[id]-1;
        }
        return -1;
    }

    event bool Zone.changed(am_addr_t node) {
        if ( node == TOS_NODE_ID ) {
            // Zone of this node changed.
            // Look for new neighbors.
            filterNbrTable();
            post dumpNbrTable();
            return TRUE;
        } else {
            // Zone of some other node changed.
            // Enqueue it for processing.
            int8_t idx = findIndex(NULL, node);
            call ZoneChangeQueue.enqueue(node);
            post processZoneChange();
            if ( idx < 0 ) return FALSE; // New node
        }
        return TRUE;    // Already exists in nbr table
    }

    event void StampTimer.fired() { }

    default event void NeighborTable.neighborAdded[uint8_t id](int8_t idx) {}

    default event void NeighborTable.neighborRemoved[uint8_t id](int8_t idx) {}

}

