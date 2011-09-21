
configuration DipDataC {
  provides interface DipDecision;

  uses interface DipSend as DataSend;
  uses interface DipReceive as DataReceive;

  uses interface ZoneDisseminationUpdate<dip_data_t>;
  uses interface ZoneDisseminationValue<dip_data_t>;

  uses interface DipHelp;
  uses interface DipEstimates;
}

implementation {
  components DipDataP;
  DipDecision = DipDataP;
  DataSend = DipDataP;
  DataReceive = DipDataP;
  ZoneDisseminationUpdate = DipDataP;
  ZoneDisseminationValue = DipDataP;
  DipHelp = DipDataP;
  DipEstimates = DipDataP;

  components LedsC;
  DipDataP.Leds -> LedsC;
}
