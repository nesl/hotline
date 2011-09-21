#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <math.h>

uint16_t normalize(uint16_t a) {
    while (a >= 360) a -= 360;
    return a;
}

#define RADIANS(a) ( (((float)(a))/360.0) * 2.0 * 3.14159)

#endif

