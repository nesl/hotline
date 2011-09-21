
#include "misc_params.h"
#include "step.h"

#define NUM_NODES           NUM_SENSORS

configuration EstimatorC {
}
implementation {
    components MainC;
    components ActiveMessageC;
    components RandomC;
    
#ifdef STATIC_PR
    components EstimatorStaticP as EstimatorP;
    components new HotlineStaticC(NUM_ACTUATORS) as HotlineC;
#else
    components EstimatorDynamicP as EstimatorP;
    components new HotlineC(NUM_ACTUATORS);
#endif

    components new ZoneIntSetC(NUM_NODES) as ZoneC;

    components DummySensorC;
    components new SensorModelC(NUM_ACTUATORS);
    components new StatisticsC(0.5, 20) as RawStatsC;
    components new StatisticsC(0.5, 20) as MeanStatsC;

    EstimatorP.Boot -> MainC;
    EstimatorP.RadioControl -> ActiveMessageC;
    EstimatorP.UserIntensity -> DummySensorC;
    EstimatorP.Random -> RandomC;
    EstimatorP.Read -> SensorModelC;
    EstimatorP.RawStats -> RawStatsC;
    EstimatorP.MeanStats -> MeanStatsC;
    EstimatorP.WaitTimer -> HotlineC.Timer[unique("HotlineTimer")];
    EstimatorP.SenseTimer -> HotlineC.Timer[unique("HotlineTimer")];
    EstimatorP.VirtualLock -> HotlineC; 
    EstimatorP.SharedMemory -> HotlineC;
    EstimatorP.Sync -> HotlineC; 
    EstimatorP.Iterations -> HotlineC; 
    EstimatorP.Zone -> ZoneC;
    
    HotlineC.Zone -> ZoneC;
    HotlineC.DebugLog -> EstimatorP;

    SensorModelC.SharedMemory -> HotlineC;

}

