
#include "zone_circle.h"

generic configuration ZoneCircleC(dip_key_t num_nodes) {
    provides interface Zone;
}

implementation {

    components MainC, ZoneCircleP;
    components new DisseminatorC(zone_circle_t, num_nodes);
    components DisseminationC;

    Zone = ZoneCircleP;

    MainC.SoftwareInit -> ZoneCircleP;

    ZoneCircleP.ZoneUpdate -> DisseminatorC;
    ZoneCircleP.ZoneValue -> DisseminatorC;
    ZoneCircleP.DisseminationControl -> DisseminationC;
}

