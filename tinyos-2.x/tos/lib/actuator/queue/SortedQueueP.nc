
#include "SortedQueue.h"

module SortedQueueP {
    provides interface SortedQueue;
    provides interface Init;

    uses interface Pool<dlist_node_t> as NodePool;
    uses interface LinkedList;
}

implementation {

    dlist_node_t* head;
    dlist_node_t *iter_node;

    dlist_node_t* find(intent_hdr_t *curr) {
        dlist_node_t *iter = head;
        if ( (head==NULL) || (curr==NULL) ) return NULL;
        for ( ; iter!=NULL; iter=(dlist_node_t*)iter->link.next ) {
            if ( iter->intent==curr ) {
                return iter;
            }
        }
        return NULL;
    }

    /***** Public Functions ******/

    command error_t Init.init() {
        head = NULL;
        iter_node = NULL;
        return SUCCESS;
    }

    command error_t SortedQueue.insert(intent_hdr_t *elm) {
        dlist_node_t* n = NULL;

        if ( elm==NULL ) return FAIL;
        
        // Allocate space for a new element
        n = call NodePool.get();
        if ( n==NULL ) return FAIL;

        // Setup the new element
        n->intent = elm;
        n->link.next = NULL;
        n->link.prev = NULL;

        // Insert it into the sorted queue (ascending order)
        if ( head==NULL ) {
            head = n;
            iter_node = NULL;
        } else {
            dlist_node_t *iter = head;
            for ( ; iter!=NULL; iter=(dlist_node_t*)iter->link.next ) {
                if ( elm->t_deadline<iter->intent->t_deadline ) {
                    // Insert before iter
                    call LinkedList.list_insert_before(
                                        (list_t**)&head, 
                                        (list_t*)iter, 
                                        (list_t*)n );
                    return SUCCESS;
                }
            }
            call LinkedList.list_insert_tail((list_t**)&head, (list_t*)n);
        }
        return SUCCESS;
    }

    command error_t SortedQueue.delete(intent_hdr_t *elm) {
        dlist_node_t *del = find(elm);
        if ( del==NULL ) return SUCCESS;
        dbg("SortedQueue", "Found pointer to element to delete.\n");
        call LinkedList.list_delete((list_t**)&head, (list_t*)del);
        call NodePool.put(del);
        return SUCCESS;
    }
    
    command intent_hdr_t* SortedQueue.getHead() {
        iter_node = head; 
        if ( head==NULL ) return NULL;
        return head->intent;
    }

    command intent_hdr_t* SortedQueue.getNext(intent_hdr_t *curr) {
        if ( (head==NULL) || (curr==NULL) ) return NULL;
        if ( (iter_node!=NULL) && (iter_node->intent==curr) ) {
            iter_node = (dlist_node_t*)iter_node->link.next;
        } else {
            dlist_node_t *iter = find(curr);
            if ( iter==NULL ) return NULL;
            iter_node = (dlist_node_t*)iter->link.next;
        }
        if ( iter_node==NULL ) return NULL;
        return iter_node->intent;
    }

    command intent_hdr_t* SortedQueue.getPrevious(intent_hdr_t *curr) {
        if ( (head==NULL) || (curr==NULL) ) return NULL;
        if ( (iter_node!=NULL) && (iter_node->intent==curr) ) {
            iter_node = (dlist_node_t*)iter_node->link.prev;
        } else {
            dlist_node_t *iter = find(curr);
            if ( iter==NULL ) return NULL;
            iter_node = (dlist_node_t*)iter->link.prev;
        }
        if ( iter_node==NULL ) return NULL;
        return iter_node->intent;
    }

}
