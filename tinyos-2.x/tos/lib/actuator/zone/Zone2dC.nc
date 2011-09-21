
#include "zone2d.h"

generic configuration Zone2dC(dip_key_t num_nodes) {
    provides interface Zone;
}

implementation {

    components MainC, Zone2dP;
    components new DisseminatorC(zone2d_t, num_nodes);
    components DisseminationC;

    Zone = Zone2dP;

    MainC.SoftwareInit -> Zone2dP;

    Zone2dP.ZoneUpdate -> DisseminatorC;
    Zone2dP.ZoneValue -> DisseminatorC;
    Zone2dP.DisseminationControl -> DisseminationC;
}

