
#include "misc_params.h"

configuration EstimatorC {
}
implementation {
    components EstimatorP, MainC;
    components RandomC;
    components new RingTransportC(NUM_ACTUATORS*sizeof(float));
    components new TimerMilliC() as BaseTimerC;
    components new VirtualizeTimerC(TMilli, uniqueCount("EstimatorTimer"))
                    as VirtualTimerC;

    components DummySensorC;

    EstimatorP.Boot -> MainC;
    EstimatorP.UserIntensity -> DummySensorC;
    EstimatorP.StampTimer -> VirtualTimerC.Timer[unique("EstimatorTimer")];
    EstimatorP.Random -> RandomC;
    
    EstimatorP.Ring -> RingTransportC;
    EstimatorP.RingControl -> RingTransportC;

    RingTransportC.Timer -> VirtualTimerC.Timer[unique("EstimatorTimer")];

    VirtualTimerC.TimerFrom -> BaseTimerC;
    
}

