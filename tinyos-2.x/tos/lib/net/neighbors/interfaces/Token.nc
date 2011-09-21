
#include <AM.h>

interface Token {
    command error_t send(uint16_t token, uint8_t frag, uint8_t seq, am_addr_t dest, void *data, uint8_t len);
    command void setRetryPeriod(uint32_t p);
    command uint8_t maxPayloadLength();
    event void sendDone(uint16_t token, uint8_t seq, error_t err);
    event void receive(uint16_t token, uint8_t frag, uint8_t seq, void *payload, uint8_t len);
    event void acked(uint16_t token, uint8_t seq);
}
