#ifndef _PRIMITIVESH_
#define _PRIMITIVESH_

/*
Primitive Solids
*/

#include <stdint.h>

#include "types.h"
#include "tracer.h"

struct LightSource; 

typedef struct RGB{
    int R, G, B; 
} RGB;

typedef struct Object{
    RGB color;
    double (*intersect)(void* , double3*, double3 *, double3 *);
} Object;


typedef struct Sphere{
    Object base;
    double3 center;
    double radius;
} Sphere;

Sphere new_Sphere(double x, double y, double z, double radius, uint8_t R, uint8_t G, uint8_t B);

#endif