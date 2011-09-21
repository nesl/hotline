#ifndef __COORD_2D_H__
#define __COORD_2D_H__

typedef nx_struct point2d_t {
    nx_uint16_t x, y;
} point2d_t;

typedef nx_struct pose2d_t {
    point2d_t loc;  /* x, y coordinates */
    nx_uint16_t a;  /* orientation about z-axis in degrees [0, 360] wrt x-axis */
} pose2d_t;

#endif

