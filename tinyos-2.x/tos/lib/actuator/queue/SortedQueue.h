#ifndef _SORTED_QUEUE_H_
#define _SORTED_QUEUE_H_

#include "d_linked_list.h"
#include "Observable.h"

typedef struct dlist_node_t {
    list_t link;
    intent_hdr_t *intent;
} dlist_node_t;

#endif

