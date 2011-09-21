#include "sensor.h"
#include "user_events.h"

module DummySensorP {
    provides interface UserIntensity;
    uses interface Receive;
}
implementation {

    uint16_t user_present, sdata;

    command void UserIntensity.init() {
        user_present = 1;
        sdata = sensor();
    }

    command uint16_t UserIntensity.get() {
        return sdata * user_present;
    }

    event message_t* Receive.receive(message_t* bufPtr, 
            void* payload, uint8_t len) {
        dbg("DummySensorP", "Received packet of length %hhu.\n", len);
        if ( len == sizeof(user_event_msg_t) ) {
            user_event_msg_t* ev = (user_event_msg_t*)payload;
            user_present = ev->value;
            signal UserIntensity.changed(sdata*user_present);
        }
        return bufPtr;
    }

}
