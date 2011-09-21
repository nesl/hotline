
#include "zone1d.h"

module Zone1dP {
    provides interface Zone;
    provides interface Init;

    uses interface ZoneDisseminationUpdate<zone1d_t> as ZoneUpdate;
    uses interface ZoneDisseminationValue<zone1d_t> as ZoneValue;
}

implementation {

    zone1d_t self_zone;

    /********* Private functions ***********/
    bool intersects(zone1d_t *nbrzone) {
        if ( (nbrzone->max <= self_zone.min) ||
             (nbrzone->min >= self_zone.max) ) {
            return FALSE;
        }
        return TRUE;
    }

    /********* Public functions ***********/

    command error_t Init.init() {
        self_zone.min = 0;
        self_zone.max = 0;
        call ZoneValue.set(TOS_NODE_ID, &self_zone);
        return SUCCESS;
    }

    command error_t Zone.set(uint8_t *newzone) {
        memcpy(&self_zone, newzone, sizeof(zone1d_t));
        call ZoneUpdate.change((dip_key_t)TOS_NODE_ID, (zone1d_t*)newzone);
        return SUCCESS;
    }
 
    command uint8_t* Zone.get(am_addr_t node_addr) {
        return (uint8_t*)call ZoneValue.get((dip_key_t)node_addr);
    }

    command bool Zone.intersects(am_addr_t nbr) {
        zone1d_t *nbrzone = (zone1d_t*)call ZoneValue.get((dip_key_t)nbr);
        return intersects(nbrzone);
    }

    event void ZoneValue.changed(dip_key_t key) {
        // Signal event so that neighbor zone updates can be handled.
        signal Zone.changed((am_addr_t)key);
    }

}

