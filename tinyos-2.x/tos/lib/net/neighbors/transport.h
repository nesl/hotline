#ifndef _TRANSPORT_H_
#define _TRANSPORT_H_

#include "locks.h"

enum {
    TRANSPORT_MSG_NEW   = 0,
    TRANSPORT_MSG_RETRY = 1,
    TRANSPORT_MSG_ACK   = 2,
    TRANSPORT_ACK_WAIT_PERIOD   = 64,
};

typedef nx_struct transport_pkt_t {
    nx_uint8_t ttype;
    lock_packet_t pkt;
} transport_pkt_t;

#endif

