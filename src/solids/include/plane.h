

#ifndef _PLANEH_
#define _PLANEH_

#include "./object.h"


typedef struct Plane{
    Solid base;
    vec3 position;
    vec3 direction;
} Plane;


Plane new_Plane(double x, double y, double z, double nx, double ny, double nz, uint8_t R, uint8_t G, uint8_t B); 

#endif