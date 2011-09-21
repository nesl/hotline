
#include "PathPlanner.h"

interface VelocityControl {
    command void set(pos_intent_t *req, uint16_t linearv, uint16_t angularv);
    event void setDone(pos_intent_t *req, uint8_t status);
}

