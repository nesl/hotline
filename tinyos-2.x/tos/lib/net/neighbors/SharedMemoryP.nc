

generic module SharedMemoryP(uint8_t M) {
    provides interface SharedMemory;

    uses interface SharedVariable;
    uses interface Cache;
}
implementation {

    float i[M];
    
    command void SharedMemory.init() {
        memset(i, 0, sizeof(i));
        call Cache.init();
    }

    command error_t SharedMemory.get(uint8_t key, float *value) {
        if ( key >= M ) return FAIL;
        *value = i[key];
        return SUCCESS;
    }

    command error_t SharedMemory.put(uint8_t key, float value) {
        error_t err;
        if ( key >= M ) return FAIL;
        if ( (err=call SharedVariable.put(key, value)) != SUCCESS ) {
            dbg("SharedMemoryPEval", "##_%s_%u_shared error\n",
                    sim_time_string(),
                    key);        // Actuator # 
            return err;
        }
        call Cache.update(key, &i[key]);
        return SUCCESS;
    }

    command void SharedMemory.flush() {
        call SharedVariable.flush();
    }

    event void SharedVariable.changed(am_addr_t n, uint8_t key, uint32_t version) {
        if ( key >= M ) return;

        if ( call Cache.processUpdate(n, key, version, &i[key]) ) {
            signal SharedMemory.changed(key);
        }
    }

    event void SharedVariable.synced(am_addr_t n) {}
}

