#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Actuation.h"
#include "zone_circle.h"

// Camera configuration parameters
#define ANGULAR_SPEED_PAN   170

#ifndef RANGE_MAX
// Default range
#define RANGE_MAX           80 // in cm
#endif

typedef struct ptz_config_t {
    uint16_t pan, tilt, zoom;
} ptz_config_t;

#endif

