
interface SharedMemory {
    command void init();
    command error_t get(uint8_t key, float *value);
    command error_t put(uint8_t key, float value);
    command void flush();
    event void changed(uint8_t key);
}

