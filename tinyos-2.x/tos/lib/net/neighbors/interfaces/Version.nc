
interface Version {
    command uint32_t getNew(uint32_t current);
    command bool changed(uint32_t current, uint32_t newv);
}

