
#include "consensus.h"
#include "misc_params.h"

#define NUM_NODES   NUM_SENSORS
#define USE_BROADCAST

//#define UNSYNC

configuration EstimatorC {
}
implementation {
    components EstimatorP, MainC;
    components ActiveMessageC;
    components RandomC;
    
    components new HotlineCC(NUM_ACTUATORS) as HotlineC;
    components ZoneCommC as ZoneC;

    components DummySensorC;

    EstimatorP.Boot -> MainC;
    EstimatorP.RadioControl -> ActiveMessageC;
    EstimatorP.Read -> DummySensorC;
    EstimatorP.Random -> RandomC;
    EstimatorP.WaitTimer -> HotlineC.Timer[unique("HotlineTimer")];
    EstimatorP.SharedMemory -> HotlineC;
    EstimatorP.Sync -> HotlineC;
    EstimatorP.NeighborTable -> HotlineC.NeighborTable[unique("NeighborTable")];

    HotlineC.Zone -> ZoneC;
    HotlineC.EdgeWeight -> EstimatorP;

}

