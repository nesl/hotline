
#include "metweights.h"

module WeightsP {
    provides interface EdgeWeight;
}
implementation {
    
    command float EdgeWeight.get(uint8_t key, am_addr_t n) {
        return W(n);
    }
}

