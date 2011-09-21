#ifndef __ZONE_CIRCLE_H__
#define __ZONE_CIRCLE_H__

#include <coord2d.h>
#include <Dip.h>

typedef nx_struct zone_circle_t {
    point2d_t center;
    nx_uint16_t radius;
} zone_circle_t;

#endif

