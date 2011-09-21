
#include "SortedQueue.h"

generic configuration SortedQueueC(uint8_t QUEUE_SIZE) {
    provides interface SortedQueue;
}

implementation {
    components MainC;
    components new PoolC(dlist_node_t, QUEUE_SIZE);
    components SortedQueueP, DLinkedListC;

    SortedQueue = SortedQueueP;
    MainC.SoftwareInit -> SortedQueueP;

    SortedQueueP.NodePool -> PoolC;
    SortedQueueP.LinkedList -> DLinkedListC;
}

