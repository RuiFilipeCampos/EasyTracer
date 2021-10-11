#ifndef _PRIMITIVESH_
#define _PRIMITIVESH_

/*
Primitive Solids
*/

#include <stdint.h>
#include "../external/cglm/include/cglm/cglm.h"

#include "types.h"
#include "tracer.h"

struct LightSource; 

typedef struct RGB{
    int R, G, B; 
} RGB;

typedef struct Object{
    RGB color;
    float (*intersect)(void* , vec3, vec3, vec3);
} Object;


typedef struct Sphere{
    Object base;
    vec3 center;
    float radius;
} Sphere;

Sphere new_Sphere(double x, double y, double z, double radius, uint8_t R, uint8_t G, uint8_t B);


typedef struct Plane{
    Object base;
    double3 position;
    double3 direction;
} Plane;


Plane new_Plane(double x, double y, double z, double nx, double ny, double nz, uint8_t R, uint8_t G, uint8_t B); 

#endif