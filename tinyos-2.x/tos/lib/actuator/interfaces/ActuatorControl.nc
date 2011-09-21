
interface ActuatorControl {
    /* Send request for setting the actuator intent */
    command error_t setIntent(intent_hdr_t *req);
    command void clearIntent(intent_hdr_t *req);
    event void controlGranted(intent_hdr_t *req);
    /* Send control commands to the actuator */
    command uint8_t setControl(intent_hdr_t *req);
    event void setControlDone(intent_hdr_t *req, uint8_t status);
}

