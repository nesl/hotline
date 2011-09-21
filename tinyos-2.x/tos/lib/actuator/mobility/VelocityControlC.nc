
#include "PathPlanner.h"

module VelocityControlC {
    provides interface VelocityControl;
    provides interface Location2d;
    provides interface Init;

    uses interface Receive as LocationSensor;
}
implementation {

    int32_t x, y;
    pos_intent_t *curr_req;

    task void send_done_task() {
        if (curr_req == NULL) return;
        signal VelocityControl.setDone(curr_req, CTRL_OK);
    }

    command error_t Init.init() {
        x = y = 0;
        curr_req = NULL;
        return SUCCESS;
    }

    command uint16_t Location2d.getX() {
        return x;
    }

    command uint16_t Location2d.getY() {
        return y;
    }

    command void VelocityControl.set(pos_intent_t *req, 
            uint16_t linearv,
            uint16_t angularv) {
        curr_req = req;
        dbg("VelocityControl", "%d:%d:%d\n", ACTUATOR_PATH_PLANNER, linearv, angularv);
        post send_done_task();
    }

    event message_t* LocationSensor.receive(message_t *msg, 
            void *payload, uint8_t len) {

        return msg;
    }

}

