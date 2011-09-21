
interface NeighborTable {
    command bool isEmpty();
    command uint16_t size();
    command int8_t getFirst();
    command int8_t getNext();
    command am_addr_t getAddress(int8_t idx);
    command bool exists(am_addr_t addr);
    command int8_t getIndex(am_addr_t addr);
    // Events to signal change of neighbors
    event void neighborAdded(int8_t idx);
    event void neighborRemoved(int8_t idx);
}

