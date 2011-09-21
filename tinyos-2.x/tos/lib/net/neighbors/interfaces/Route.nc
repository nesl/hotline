
interface Route {
    command int8_t get(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len);
}

