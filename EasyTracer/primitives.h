#ifndef _TRACERH_
#define _TRACERH_

/*
Primitive Solids
*/
#include "types.h"

typedef struct RGB{
    int R, G, B; 
}RGB;

typedef struct Object{
    RGB color;
    double (*intersect)(void* , double3 *, double3 *);
} Object;


typedef struct Sphere{
    Object base;
    double3 center;
    double radius;
} Sphere;


Sphere new_Sphere(double x, double y, double z, double radius);

#endif