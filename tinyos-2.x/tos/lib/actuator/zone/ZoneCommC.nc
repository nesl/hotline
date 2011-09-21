
configuration ZoneCommC {
    provides interface Zone;
}
implementation {

    enum {
        AM_NBR_BEACON = 23,
    };

    components MainC, ZoneCommP;
    components new AMSenderC(AM_NBR_BEACON) as RadioSend;
    components new AMReceiverC(AM_NBR_BEACON) as RadioRcv;
    components new NbrTrickleTimerMilliC(64, 32*1024L) as BeaconTimerC;

    Zone = ZoneCommP;

    MainC.SoftwareInit -> ZoneCommP;

    ZoneCommP.Packet -> RadioSend;
    ZoneCommP.AMPacket -> RadioSend;
    ZoneCommP.AMSend -> RadioSend;
    ZoneCommP.Receive -> RadioRcv;
    ZoneCommP.BeaconTimer -> BeaconTimerC;
}

