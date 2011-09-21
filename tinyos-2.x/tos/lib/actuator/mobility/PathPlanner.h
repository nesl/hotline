#ifndef _PATHPLANNER_H_
#define _PATHPLANNER_H_

#include "Observable.h"

#define AM_LOCATION_SENSOR      20
#define REQUEST_QUEUE_SIZE      5

typedef nx_struct {
    nx_int32_t x1, y1, x2, y2;
} area_rectangle_t;

typedef nx_struct {
    nx_uint16_t linear, angular;
} velocity_t;

typedef nx_struct pos_intent_t {
    intent_hdr_t info;      // Intent header must be the first element.
    area_rectangle_t range;
} pos_intent_t;

typedef nx_struct {
    intent_hdr_t info;
    velocity_t v;
} vel_control_t;

#endif

