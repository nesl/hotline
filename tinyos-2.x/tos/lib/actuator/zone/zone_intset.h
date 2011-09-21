#ifndef __ZONE_INTSET_H__
#define __ZONE_INTSET_H__

#include <Dip.h>

#define SET_MAX_ELEMENTS    15

typedef nx_struct zone_intset_t {
    nx_uint8_t element[SET_MAX_ELEMENTS];
    nx_uint8_t size;
} zone_intset_t;

#endif

