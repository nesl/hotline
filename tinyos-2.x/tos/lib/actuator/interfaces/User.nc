
interface User<t> { 
    command error_t request(t zone, uint16_t min, uint16_t max);
    command error_t enable();
    command error_t disable();
    event void requestDone(error_t err);
}   
