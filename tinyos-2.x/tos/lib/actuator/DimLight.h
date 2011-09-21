#ifndef __DIMLIGHT_H__
#define __DIMLIGHT_H__

#define MIN_DIM_LEVEL   0
#define MAX_DIM_LEVEL   10

#define LIGHT_CONSTANT  100

typedef struct dim_config_t {
    uint8_t dimlevel;
} dim_config_t;

#endif

