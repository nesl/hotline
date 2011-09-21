
generic configuration SensorModelC(uint8_t M) {
    provides interface Read<uint16_t>;
    uses interface SharedMemory;
}
implementation {
    components MainC;
    components new SensorModelP(NUM_ACTUATORS);

    Read = SensorModelP;
    SharedMemory = SensorModelP;

    MainC.SoftwareInit -> SensorModelP;
}

