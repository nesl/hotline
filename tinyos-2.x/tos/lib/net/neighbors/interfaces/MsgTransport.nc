
interface MsgTransport {
    command error_t send(lock_packet_t *pkt, am_addr_t destAddr);
    command void clearAll();
    command am_addr_t address();
    command void setMaxRetries(uint8_t max);
    command void setRetryPeriod(uint32_t period);
    event void sendDone(lock_packet_t *pkt, am_addr_t destAddr, error_t err);
    event lock_packet_t* receive(lock_packet_t *pkt, am_addr_t srcAddr);
}
