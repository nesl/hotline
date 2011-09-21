
interface Cache {
    command void init();
    command void update(uint8_t key, float *v);
    command bool processUpdate(am_addr_t n, uint8_t key, uint32_t version,
            float *v); 
}
