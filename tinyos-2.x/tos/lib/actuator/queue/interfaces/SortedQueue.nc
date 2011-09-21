
interface SortedQueue {
    command error_t insert(intent_hdr_t *elm);
    command error_t delete(intent_hdr_t *elm);
    command intent_hdr_t *getHead();
    command intent_hdr_t* getNext(intent_hdr_t *curr);
    command intent_hdr_t* getPrevious(intent_hdr_t *curr);
}

