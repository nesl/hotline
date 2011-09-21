
#include <routes.h>

module RouteManagerP {
    provides interface Route;
}

implementation {

    command int8_t Route.get(am_addr_t dest, nx_am_addr_t *hops, 
                              int8_t max_len) {
        return fill_route(dest, hops, max_len);
    }
    
}

