
interface VarTransport {
    command error_t send(shared_vars_t *data, uint8_t *used, bool reTx);
    event void receive(am_addr_t src, var_t *data,
            uint8_t num_vars, uint32_t seq, uint16_t mmask, uint16_t pmask);

    command am_addr_t address();
    command void clearAll();
}

