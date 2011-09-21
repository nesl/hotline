
#ifdef REAL_WORLD_REMOVE
#include <printf.h>
#endif

#include "zone_circle.h"

module ZoneCircleP {
    provides interface Zone;
    provides interface Init;

    uses interface StdControl as DisseminationControl;
    uses interface ZoneDisseminationUpdate<zone_circle_t> as ZoneUpdate;
    uses interface ZoneDisseminationValue<zone_circle_t> as ZoneValue;
}

implementation {

    bool diss_started;
    zone_circle_t self_zone;

    /********* Private functions ***********/
    bool intersects(zone_circle_t *nbrzone) {
        int32_t x2 = (int32_t)self_zone.center.x-
            (int32_t)nbrzone->center.x;
        int32_t X2 = x2 * x2;
        int32_t y2 = (int32_t)self_zone.center.y-
            (int32_t)nbrzone->center.y;
        int32_t Y2 = y2 * y2;
#ifdef PLATFORM_TELOSB
        float dist = sqrtf(X2 + Y2);
#else
        float dist = sqrt(X2 + Y2);
#endif
#ifdef REAL_WORLD_REMOVE
        printf("(%d)\n", (int)dist);
        printfflush();
#endif
        if ( dist < (float)(self_zone.radius+nbrzone->radius) ) return TRUE;
        return FALSE;
    }

    /********* Public functions ***********/

    command error_t Init.init() {
        diss_started = FALSE;
        self_zone.center.x = 0;
        self_zone.center.y = 0;
        self_zone.radius = 0;
        return SUCCESS;
    }

    command error_t Zone.enable() {
        if ( diss_started ) return SUCCESS;
        diss_started = TRUE;
        return call DisseminationControl.start();
    }

    command error_t Zone.disable() {
        if ( diss_started ) {
            diss_started = FALSE;
            return call DisseminationControl.stop();
        }
        return SUCCESS;
    }

    command error_t Zone.set(uint8_t *newzone) {
        if ( !diss_started ) return FAIL;
        memcpy(&self_zone, newzone, sizeof(zone_circle_t));
        call ZoneUpdate.change((dip_key_t)TOS_NODE_ID, (zone_circle_t*)newzone);
        return SUCCESS;
    }
 
    command uint8_t* Zone.get(am_addr_t node_addr) {
        if ( !diss_started ) return NULL;
        return (uint8_t*)call ZoneValue.get((dip_key_t)node_addr);
    }

    command bool Zone.intersects(am_addr_t nbr) {
        zone_circle_t *nbrzone = (zone_circle_t*)call ZoneValue.get((dip_key_t)nbr);
        if ( !diss_started ) return FALSE;
#ifdef REAL_WORLD_REMOVE
        printf("Self: Center-(%u,%u) Radius-(%u)\n",
                self_zone.center.x, self_zone.center.y, self_zone.radius);
        printfflush();
        printf("Neighbor %u: Center-(%u,%u) Radius-(%u) Distance-",
                nbr, nbrzone->center.x, nbrzone->center.y, nbrzone->radius);
#endif
        return intersects(nbrzone);
    }

    event void ZoneValue.changed(dip_key_t key) {
        if ( !diss_started ) return;
        // Signal event so that neighbor zone updates can be handled.
        signal Zone.changed((am_addr_t)key);
    }

}

