
generic module CacheSyncAvgP(uint8_t M) {
    provides interface Cache;

    uses interface SharedVariable;
    uses interface NeighborTable;
    uses interface EdgeWeight;
}
implementation {

    bool do_cache_update(uint8_t key, float *v) {
        float i = 0;
        int8_t n;
        call SharedVariable.get(TOS_NODE_ID, key, &i);
        i *= call EdgeWeight.get(key, TOS_NODE_ID);
        for ( n=call NeighborTable.getFirst();
                n!=-1; n=call NeighborTable.getNext() )
        {
            uint16_t naddr = call NeighborTable.getAddress(n);
            float n_est = 0;
            call SharedVariable.get(naddr, key, &n_est);
            i += ( call EdgeWeight.get(key, naddr) * n_est );
        }
        *v = i;
        dbg("CacheSyncPEval", "##_%s_%u_%f_cache udpate\n",
                sim_time_string(),
                key,
                i);
        return TRUE;
    }

    command void Cache.init() {}

    command void Cache.update(uint8_t key, float *v) {
        do_cache_update(key, v);
    }

    command bool Cache.processUpdate(am_addr_t nbr, uint8_t key, 
            uint32_t version, float *v) {
        return do_cache_update(key, v);
    }

    event void SharedVariable.changed(am_addr_t n, uint8_t key, uint32_t version) {}
    event void SharedVariable.synced(am_addr_t n) {}
    event void NeighborTable.neighborAdded(int8_t idx) {}
    event void NeighborTable.neighborRemoved(int8_t idx) {}

}

