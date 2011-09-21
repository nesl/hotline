
generic module DataStoreC(typedef data_t, uint8_t STORE_SIZE) {
    provides interface DataStore<data_t>;
    provides interface Init;
}

implementation {

    typedef struct {
        uint8_t in_use;
    } meta_t;

    data_t store[STORE_SIZE];
    meta_t meta[STORE_SIZE];

    int16_t iter_idx;

    data_t* get_next() {
        int16_t i;
        for ( i=iter_idx; i<STORE_SIZE; i++ ) {
            if ( meta[i].in_use ) {
                iter_idx = ( (i+1)>=STORE_SIZE ) ? -1 : i+1;
                return &store[i];
            }
        }
        iter_idx = -1;
        return NULL;
    }

    /***** Public Functions ******/

    command error_t Init.init() {
        iter_idx = -1;
        memset(meta, 0, STORE_SIZE*sizeof(meta_t));
        return SUCCESS;
    }

    command data_t* DataStore.getNewElement() {
        uint8_t i = 0;
        for ( i=0; i<STORE_SIZE; i++ ) {
            if ( meta[i].in_use ) continue;
            meta[i].in_use = 1;
            return &store[i];
        }

        return NULL;
    }

    command void DataStore.deleteElement(data_t* elm) {
        uint32_t idx;
        if ( ((uint32_t)elm<(uint32_t)&store[0]) || 
             ((uint32_t)elm>(uint32_t)&store[STORE_SIZE-1]) ) {
            return;
        }
        idx = ((uint32_t)elm - (uint32_t)&store[0]) / sizeof(data_t);
        meta[idx].in_use = 0;
    }

    command data_t* DataStore.getFirst() {
        iter_idx = 0;
        return get_next();
    }

    command data_t* DataStore.getNext() {
        if ( iter_idx<0 ) return NULL;
        return get_next();
    }
}
