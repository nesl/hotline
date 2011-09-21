
interface UserIntensity {
    command void init();
    command uint16_t get();
    event void changed(uint16_t val);
}

