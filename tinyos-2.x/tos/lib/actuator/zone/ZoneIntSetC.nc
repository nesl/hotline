
#include "zone_intset.h"

generic configuration ZoneIntSetC(dip_key_t num_nodes) {
    provides interface Zone;
}
implementation {

    components MainC, ZoneIntSetP;
    components new DisseminatorC(zone_intset_t, num_nodes);
    components DisseminationC;

    Zone = ZoneIntSetP;

    MainC.SoftwareInit -> ZoneIntSetP;

    ZoneIntSetP.ZoneUpdate -> DisseminatorC;
    ZoneIntSetP.ZoneValue -> DisseminatorC;
    ZoneIntSetP.DisseminationControl -> DisseminationC;
}

