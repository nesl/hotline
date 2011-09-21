configuration EstimatorC {}
implementation {
    components EstimatorP, MainC, ActiveMessageC;
    components CollectionC as Collector;
    components DummySensorC, RandomC;
    components new CollectionSenderC(0xee);
    components new TimerMilliC();

    EstimatorP.Boot -> MainC;
    EstimatorP.RadioControl -> ActiveMessageC;
    EstimatorP.RoutingControl -> Collector;
    EstimatorP.RootControl -> Collector;
    EstimatorP.Timer -> TimerMilliC;
    EstimatorP.Send -> CollectionSenderC;
    EstimatorP.Intercept -> Collector.Intercept[0xee];
    EstimatorP.Receive -> Collector.Receive[0xee];
    EstimatorP.Read -> DummySensorC;
    EstimatorP.Random -> RandomC;
}
