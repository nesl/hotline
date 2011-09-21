#ifndef __LOCKS_H__
#define __LOCKS_H__

#include "Neighbor.h"

enum {
    LOCK_QUEUE_SIZE = NEIGHBOR_TABLE_SIZE,
    AM_VIRTUAL_LOCK = 11,
};

#define MSGCOUNT_ALPHA  0.5
#define RT_ALPHA        0.2
#define RT_THRESH       0.1
#define MSGCOUNT_THRESH 0.1

enum {
    MAX_TRIES_PIP               = 2,
    MIN_APP_WAIT_PERIOD         = 20,
    MIN_REQUEST_WAIT_PERIOD     = 512,
    MIN_TIMER_PERIOD            = 20,
    MIN_HOLD_TIME               = 50,
    MIN_HOLD_FACTOR             = 1,
    DEFAULT_HOLD_FACTOR         = 8,
    MAX_HOLD_FACTOR             = 16,
};

// Lock grant status
enum {
    LOCK_GRANT_NORMAL         = 0,
    LOCK_GRANT_TRY_EXPIRED    = -1,
    LOCK_GRANT_HOLD_EXPIRED   = -2,
};

// Lock state machine
enum {
    LOCK_STATUS_IDLE            = 0,
    LOCK_STATUS_WAIT_ACQUIRE    = 1,    // Not used any more.
    LOCK_STATUS_WAIT_REQUEST    = 2,
    LOCK_STATUS_WAIT_DONE       = 3,
    LOCK_STATUS_TRY_EXPIRED     = 4,
    LOCK_STATUS_HOLD            = 5,
    LOCK_STATUS_APP_WAIT        = 6,
};

// Lock msg type
enum {
    LOCK_MSG_REQUEST    = 0,
    LOCK_MSG_CONFLICT   = 1,
    LOCK_MSG_DONE       = 2,
    LOCK_MSG_HOLD       = 3,
    LOCK_MSG_ACK        = 4,
};

// Neighbor status
enum {
    LOCK_NODE_IDLE          = 0x01,
    LOCK_NODE_RX_REQUEST    = 0x02,    /* Rcvd request from this node and
                                          replied to it */
    LOCK_NODE_RX_CONFLICT   = 0x04,    /* Rcvd conflict from this node */
    LOCK_NODE_TX_REQUEST    = 0x08,    /* Txed request to this node */
    LOCK_NODE_RX_REQUEST_LOW= 0x10,    /* Rcvd low priority request from this node */
};

// Neighbor lock table entry
typedef struct lock_t {
    int8_t status;
    int8_t rank;
    uint32_t metric;
    uint32_t holdtime;
    uint32_t lastseq;
    uint32_t rcvcnt;
} lock_t;

// Lock msg sent over the network
typedef nx_struct lock_packet_t {
    nx_uint8_t msgtype;
    nx_uint32_t seq;
    nx_uint32_t metric;
    nx_uint32_t holdtime;
    nx_am_addr_t srcAddr;
    nx_am_addr_t destAddr;
} lock_packet_t;

typedef struct lock_queue_t {
    lock_packet_t data;
    int8_t retries;
    bool acked;
    am_addr_t nextHop;
} lock_queue_t;

#endif

