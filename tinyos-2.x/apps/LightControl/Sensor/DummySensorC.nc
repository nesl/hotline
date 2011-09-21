#include "user_events.h"

configuration DummySensorC {
    provides interface UserIntensity;
}
implementation {

    components DummySensorP;
    components new AMReceiverC(AM_USER_EVENT_MSG);
  
    UserIntensity = DummySensorP;

    DummySensorP.Receive -> AMReceiverC;
}

