
interface Stats {
    command void init(); 
    command void add(uint16_t n_elt);
    command uint16_t getMean();
    command bool varianceHigh(uint32_t threshold);
    command bool ewmaChanged(uint32_t threshold);
}

