

generic module CacheSyncLatestP(uint8_t M) {
    provides interface Cache;

    uses interface SharedVariable;
    uses interface Timer<TMilli> as StampTimer;
}
implementation {

    uint32_t curr_version[M];
    
    bool do_cache_update(am_addr_t n, uint8_t key, 
            uint32_t version, float *v) {
        if ( version >= curr_version[key] ) {
            // Get the new variable from sensor n and store the new version
            curr_version[key] = version;
            call SharedVariable.get(n, key, v);   // Can't fail
            dbg("CachePEval", "##_%s_%u_%f_cache udpate\n",
                    sim_time_string(),
                    key,
                    *v);
            return TRUE;
        }
        return FALSE;
    }

    command void Cache.init() {
        memset(curr_version, 0, sizeof(curr_version));
    }

    command void Cache.update(uint8_t key, float *v) {
        uint32_t version = call StampTimer.getNow(); 
        do_cache_update(TOS_NODE_ID, key, version, v);
    }

    command bool Cache.processUpdate(am_addr_t n, uint8_t key, 
            uint32_t version, float *v) {
        return do_cache_update(n, key, version, v);
    }

    event void SharedVariable.changed(am_addr_t n, uint8_t key, uint32_t version) {}
    event void SharedVariable.synced(am_addr_t n) {}
    event void StampTimer.fired() {}
}

