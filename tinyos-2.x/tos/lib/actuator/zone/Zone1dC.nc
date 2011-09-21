
#include "zone1d.h"

generic configuration Zone1dC(dip_key_t num_nodes) {
    provides interface Zone;
}

implementation {

    components MainC, Zone1dP;
    components new DisseminatorC(zone1d_t, num_nodes);

    Zone = Zone1dP;

    MainC.SoftwareInit -> Zone1dP;

    Zone1dP.ZoneUpdate -> DisseminatorC;
    Zone1dP.ZoneValue -> DisseminatorC;
}

