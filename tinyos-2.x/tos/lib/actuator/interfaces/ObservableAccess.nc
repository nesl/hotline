
interface ObservableAccess<t> { 
    command error_t enable();
    command error_t disable();
    command uint16_t read();
    command error_t write(uint16_t val);
    command uint32_t getTimeToActuate(t* target, t* from);
}
