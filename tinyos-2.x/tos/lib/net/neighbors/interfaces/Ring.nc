
#include <AM.h>

interface Ring {
    command error_t sendToNext(uint16_t token, void *data, uint16_t len);
    event void sendDone(uint16_t token, error_t err);
    event void receive(uint16_t token, void *payload, uint16_t len);
}
