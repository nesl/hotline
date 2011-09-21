#include "d_linked_list.h"

module DLinkedListC {
    provides interface LinkedList;
}

implementation {
    command void LinkedList.list_insert_before(list_t **head, list_t *pos, list_t *elm) {
        if ( *head==NULL ) {
            *head = elm;
        } else {
            if ( pos==NULL ) return;
            elm->next = pos;
            elm->prev = pos->prev;
            if ( pos->prev!=NULL ) {
                pos->prev->next = elm;
            } else {
                // 'pos' was at head of list. Update head.
                *head = elm;
            }
            pos->prev = elm;
        }
    }

    command void LinkedList.list_insert_tail(list_t **head, list_t *elm) {
        if ( *head==NULL ) {
            *head = elm;
        } else {
            list_t *iter=*head;
            for ( ; iter->next!=NULL; iter=iter->next ) {}
            iter->next = elm;
            elm->prev = iter;
        }
    }

    command void LinkedList.list_delete(list_t **head, list_t *del) {
        if ( *head==NULL ) return;
        if ( *head==del ) {
            *head = (*head)->next;
            if ( *head!=NULL ) {
                (*head)->prev = NULL;
            }
        } else {
            list_t *n = del->next;
            list_t *p = del->prev;
            p->next = n;
            if ( n!=NULL ) {
                n->prev = p;
            }
        }
    }

}

