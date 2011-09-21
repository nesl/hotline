
interface ObservableTransaction<t> {
    command error_t activate(t area, uint16_t min, uint16_t max);
    event void activateDone(int8_t err, uint16_t min, uint16_t max);

    command error_t beginTransaction();
    command error_t endTransaction(int8_t cmd);
    event void transactionDone(error_t err);
}

