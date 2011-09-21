
#include "zone2d.h"

module Zone2dP {
    provides interface Zone;
    provides interface Init;

    uses interface StdControl as DisseminationControl;
    uses interface ZoneDisseminationUpdate<zone2d_t> as ZoneUpdate;
    uses interface ZoneDisseminationValue<zone2d_t> as ZoneValue;
}

implementation {

    bool diss_started;
    zone2d_t self_zone;

    /********* Private functions ***********/
    typedef enum {
        PARALLEL    = 0,
        CONINCIDENT,
        NON_INTERSECTING,
        INTERSECTING,
    } intersect_result_t;

    ////////////////////////////////////////////////////////////////
    // 
    // Point Inclusion in Polygon Test
    // Polygon: z->v[], Point: pt
    //
    // Adapted from code written by W. Randolph Franklin
    // http://www.ecse.rpi.edu/Homepages/wrf/Research/Short_Notes/pnpoly.html#The%20C%20Code
    // (Please see website for license)
    ////////////////////////////////////////////////////////////////
    uint8_t pnpoly(zone2d_t *z, point2d_t *pt) {
        uint8_t c = 0;
        uint8_t i, j;
        uint8_t nvert = z->numv;
        for (i = 0, j = nvert-1; i < nvert; j = i++) {
            if ( (z->v[i].y > pt->y) != (z->v[j].y > pt->y) ) {
                // First condition is true. Check the next condition.
                int32_t mterm = z->v[j].y - z->v[i].y;
                int32_t rhs = (z->v[j].x - z->v[i].x) * (pt->y - z->v[i].y) +
                     (z->v[i].x * mterm);
                int32_t lhs = mterm * pt->x;
                if ( ((mterm < 0) && (lhs > rhs)) ||
                     ((mterm > 0) && (lhs < rhs)) ) {
                    c = !c;
                }
            }
        }
        return c;
    }

    ////////////////////////////////////////////////////////////////
    // 
    // 2D Line Segment Intersection 
    // Line segments: [a, b], [c, d]
    // Implementation of the theory provided by Paul Bourke
    // 
    // Adapted from code written by Damian Coventry
    // 
    ////////////////////////////////////////////////////////////////
    intersect_result_t check_intersection(point2d_t *a, point2d_t *b,
                                          point2d_t *c, point2d_t *d) {
        int32_t denom = (d->y-c->y)*(b->x-a->x) - (d->x-c->x)*(b->y-a->y);
        int32_t numu_a = (d->x-c->x)*(a->y-c->y) - (d->y-c->y)*(a->x-c->x);
        int32_t numu_b = (b->x-a->x)*(a->y-c->y) - (b->y-a->y)*(a->x-c->x);
        float u_a = 0.0, u_b = 0.0;

        if ( denom == 0 ) {
            if ( (numu_a == 0) && (numu_b == 0) ) {
                return CONINCIDENT;
            }
            return PARALLEL;
        }

        u_a = (float)numu_a/(float)denom;
        u_b = (float)numu_b/(float)denom;

        if ( (u_a>=0.0) && (u_a<=1.0) && 
             (u_b>=0.0) && (u_b<=1.0) ) {
            return INTERSECTING;
        }

        return NON_INTERSECTING;
    }

    bool intersects(zone2d_t *nbrzone) {
        uint8_t i, j;
        point2d_t corner_lb1, corner_rt1;
        point2d_t corner_lb2, corner_rt2;

        for ( i=0; i<self_zone.numv; i++ ) {
            point2d_t *a = &self_zone.v[i];
            point2d_t *b = &self_zone.v[(i+1)%self_zone.numv];
            for ( j=0; j<nbrzone->numv; i++ ) {
                intersect_result_t res = check_intersection(
                        a, b,
                        &nbrzone->v[j],
                        &nbrzone->v[(j+1)%nbrzone->numv]);
                if ( res == INTERSECTING ) {
                    return TRUE;
                }
            }
        }
        // None of the polygon edges intersect.
        // Now check for complete overlap by using point inclusion in polygon
        // test.
        if ( pnpoly(&self_zone, &nbrzone->v[0]) ||
                pnpoly(nbrzone, &self_zone.v[0]) ) {
            return TRUE;
        }

        return FALSE;
    }

    /********* Public functions ***********/

    command error_t Init.init() {
        diss_started = FALSE;
        memset(&self_zone, 0, sizeof(zone2d_t));
        //call ZoneValue.set(TOS_NODE_ID, &self_zone);
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
        memcpy(&self_zone, newzone, sizeof(zone2d_t));
        call ZoneUpdate.change((dip_key_t)TOS_NODE_ID, (zone2d_t*)newzone);
        return SUCCESS;
    }
 
    command uint8_t* Zone.get(am_addr_t node_addr) {
        if ( !diss_started ) return NULL;
        return (uint8_t*)call ZoneValue.get((dip_key_t)node_addr);
    }

    command bool Zone.intersects(am_addr_t nbr) {
        zone2d_t *nbrzone = (zone2d_t*)call ZoneValue.get((dip_key_t)nbr);
        if ( !diss_started ) return FALSE;
        return intersects(nbrzone);
    }

    event void ZoneValue.changed(dip_key_t key) {
        if ( !diss_started ) return;
        // Signal event so that neighbor zone updates can be handled.
        signal Zone.changed((am_addr_t)key);
    }

}
