#include <deployment.h>

generic module SensorModelP(uint8_t M) {
    provides interface Init;
    provides interface Read<uint16_t>;

    uses interface SharedMemory;
}
implementation {
    bool busy;

    uint16_t sensor_read() {
        float Li = (float)ambient();
        uint8_t j;
        for ( j=0; j<M; j++ ) {
            float i = 0;
            if ( A_i(j) == 0 ) continue;
            call SharedMemory.get(j, &i);
            Li += ( A_i(j) * i );
        }
        return (uint16_t)Li;
    }

    task void send_data() {
        busy = FALSE;
        signal Read.readDone(SUCCESS, sensor_read());
    }

    command error_t Init.init() {
        busy = FALSE;
        return SUCCESS;
    }

    command error_t Read.read() {
        if ( !busy ) {
            busy = TRUE;
            post send_data();
        }
        return SUCCESS;
    }

    event void SharedMemory.changed(uint8_t key) {}
}
