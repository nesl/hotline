
#include "consensus.h"
#include "misc_params.h"

#include "step.h"

#define NUM_NODES   NUM_SENSORS

configuration EstimatorC {
}
implementation {
    components EstimatorP, WeightsP, MainC;
    components ActiveMessageC;
    components RandomC;
    
    components new HotlineCC(NUM_ACTUATORS) as HotlineC;
    components new ZoneIntSetC(NUM_NODES) as ZoneC;

    components DummySensorC;
    components new SensorModelC(NUM_ACTUATORS);
    components new StatisticsC(0.5, 20) as RawStatsC;

    EstimatorP.Boot -> MainC;
    EstimatorP.RadioControl -> ActiveMessageC;
    EstimatorP.Random -> RandomC;
    EstimatorP.UserIntensity -> DummySensorC;
    EstimatorP.Read -> SensorModelC;
    EstimatorP.RawStats -> RawStatsC;
    EstimatorP.WaitTimer -> HotlineC.Timer[unique("HotlineTimer")];
    EstimatorP.SenseTimer -> HotlineC.Timer[unique("HotlineTimer")];
    EstimatorP.SharedMemory -> HotlineC;
    EstimatorP.Sync -> HotlineC; 
    EstimatorP.Zone -> ZoneC;
    
    HotlineC.Zone -> ZoneC;
    HotlineC.DebugLog -> EstimatorP;
    HotlineC.EdgeWeight -> WeightsP;

    SensorModelC.SharedMemory -> HotlineC;

}

