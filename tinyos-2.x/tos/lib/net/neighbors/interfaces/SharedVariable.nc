
interface SharedVariable {
    command error_t get(am_addr_t n, uint8_t key, float *value);
    command error_t put(uint8_t key, float value);
    command error_t remove(uint8_t key);
    command void flush();
    command bool isConsistent(am_addr_t n);
    // Events to signal change of neighbors
    event void changed(am_addr_t n, uint8_t key, uint32_t version);
    event void synced(am_addr_t n);
}

