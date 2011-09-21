#ifndef _SOURCE_ROUTE_H_
#define _SOURCE_ROUTE_H_

#include <AM.h>
#include <message.h>

#include <src_route_config.h>

#define UQ_SOURCE_ROUTE         unique("SourceRoute")
#define UQCOUNT_SOURCE_ROUTE    uniqueCount("SourceRoute")

enum {
    AM_SOURCE_ROUTE = 17,
    //SRC_MAX_HOPS    = 4, - Moved to header file
    MAX_QUEUE_LEN   = UQCOUNT_SOURCE_ROUTE + 1,
};

typedef enum {
    ACTION_TX   = 0,
    ACTION_FWD,
} action_t;

typedef nx_struct src_hdr_t {
    nx_uint8_t type;
    nx_uint8_t len;
    nx_int8_t idx;
    nx_am_addr_t route[SRC_MAX_HOPS];
} src_hdr_t;

typedef struct msg_queue_t {
    action_t action;
    message_t *msg;
} msg_queue_t;

#endif

