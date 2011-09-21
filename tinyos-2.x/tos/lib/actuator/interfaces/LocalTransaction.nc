
interface LocalTransaction<t> {
    /* Begin the transaction */
    command error_t begin(t area, uint16_t min, uint16_t max);
    /* Commit the result to the actuator */
    command error_t commit();
    /* Revert back to previous value of actuator */
    command error_t revert();
    /* Signal that the transaction can continue */
    event void doContinue(int8_t err, uint16_t min, uint16_t max);
    event void committed(error_t err);
}

