#ifndef _ROUTE_FRAGMENT_H_
#define _ROUTE_FRAGMENT_H_

#include "source_route.h"

enum {
    DEFAULT_RETRY_PERIOD = 256,
};

enum {
    RING_TOKEN  = UQ_SOURCE_ROUTE,
    RING_ACK    = UQ_SOURCE_ROUTE,
};

typedef enum {
    STATE_IDLE  = 0,
    STATE_SENDING,
    STATE_WAITING,
} state_t;

typedef nx_struct tr_hdr_t {
    nx_uint16_t token;
    nx_am_addr_t src;
    nx_uint8_t frag;
    nx_uint8_t seq;
} tr_hdr_t;

#endif

