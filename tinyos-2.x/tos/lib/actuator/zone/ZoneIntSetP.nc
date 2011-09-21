
#ifdef REAL_WORLD
#include <printf.h>
#endif

#include "zone_intset.h"

module ZoneIntSetP {
    provides interface Zone;
    provides interface Init;

    uses interface StdControl as DisseminationControl;
    uses interface ZoneDisseminationUpdate<zone_intset_t> as ZoneUpdate;
    uses interface ZoneDisseminationValue<zone_intset_t> as ZoneValue;
}

implementation {

    bool diss_started;
    zone_intset_t self_zone;

    /********* Private functions ***********/
    bool intersects(zone_intset_t *nbrzone) {
        uint8_t i, j;
        for ( i=0; i<self_zone.size; i++) {
            for ( j=0; j<nbrzone->size; j++ ) {
                if ( self_zone.element[i] == nbrzone->element[j] ) {
                    return TRUE;
                }
            }
        }
        return FALSE;
    }

    /********* Public functions ***********/

    command error_t Init.init() {
        diss_started = FALSE;
        memset(&self_zone, 0, sizeof(self_zone));
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
        memcpy(&self_zone, newzone, sizeof(zone_intset_t));
        call ZoneUpdate.change((dip_key_t)TOS_NODE_ID, (zone_intset_t*)newzone);
        return SUCCESS;
    }
 
    command uint8_t* Zone.get(am_addr_t node_addr) {
        if ( !diss_started ) return NULL;
        return (uint8_t*)call ZoneValue.get((dip_key_t)node_addr);
    }

    command bool Zone.intersects(am_addr_t nbr) {
        zone_intset_t *nbrzone = (zone_intset_t*)call ZoneValue.get((dip_key_t)nbr);
        if ( !diss_started ) return FALSE;
#ifdef REAL_WORLD
        uint8_t i;
        printf("Self: ");
        for ( i=0; i<self_zone.size; i++) {
            printf("%u ", self_zone.element[i]);
        }
        printf("\n");
        printfflush();
        printf("Neighbor [%u]: ", nbr);
        for ( i=0; i<nbrzone->size; i++ ) {
            printf("%u ", nbrzone->element[i]);
        }
        printf("\n");
        printfflush();
#endif
        return intersects(nbrzone);
    }

    event void ZoneValue.changed(dip_key_t key) {
        if ( !diss_started ) return;
        // Signal event so that neighbor zone updates can be handled.
        signal Zone.changed((am_addr_t)key);
    }

}
