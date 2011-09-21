
#include <Dip.h>

configuration DipVersionC {
  provides interface DipHelp;

  provides interface ZoneDisseminationUpdate<dip_data_t>;
}

implementation {
  components DipVersionP;
  DipHelp = DipVersionP;
  ZoneDisseminationUpdate = DipVersionP;
}
