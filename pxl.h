
#ifndef PXL_H
#define PXL_H 1

#include <stdint.h>

#define IMAGE_MODE_RGBA 0
#define IMAGE_MODE_L 1

typedef uint8_t mode_t;
typedef uint32_t unit_t;
typedef uint8_t color_unit_t;

typedef struct
{
    color_unit_t r;
    color_unit_t g;
    color_unit_t b;
} color_rgb_t;

typedef struct
{
    color_unit_t r;
    color_unit_t g;
    color_unit_t b;
    color_unit_t a;
} color_rgba_t;

typedef struct
{
    unit_t x;
    unit_t y;
} vector_2d_t;

typedef struct
{
    mode_t mode;
    vector_2d_t size;
    void *buffer;
    void *colors;
} image;

#endif

