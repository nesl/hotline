#ifndef __NEIGHBOR_H__
#define __NEIGHBOR_H__

#include <AM.h>

#define UQ_NBRTABLE         unique("NeighborTable")
#define UQCOUNT_NBRTABLE    uniqueCount("NeighborTable")

// Number of entries in the neighbor table
enum {
    NEIGHBOR_TABLE_SIZE = 40,
};

// Flags for the neighbor table entry
enum {
    INUSE_ENTRY = 0x1,
};

// neighbor table entry
typedef struct neighbor_t {
    // link layer address of the neighbor
    am_addr_t ll_addr;
    // last beacon sequence number received from this neighbor
    uint32_t lastseq;
    // number of msgs received from this neighbor
    uint8_t rcvcnt;
    // flags to describe the state of this entry
    uint8_t flags;
    // pointer to some neighbor data
    uint8_t *zone;
} neighbor_t;

#endif

