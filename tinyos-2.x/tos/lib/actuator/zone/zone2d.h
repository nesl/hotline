#ifndef __ZONE2D_H__
#define __ZONE2D_H__

#include <coord2d.h>
#include <Dip.h>

#define MAX_NUM_VERTICES    4

typedef nx_struct zone2d_t {
    nx_uint8_t numv;
    point2d_t v[MAX_NUM_VERTICES];  /* Clockwise order */
} zone2d_t;

#endif

