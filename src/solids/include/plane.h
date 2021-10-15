

#ifndef _PLANEH_
#define _PLANEH_

#include "../../../external/cglm/include/cglm/cglm.h"
#include "./object.h"


typedef struct Plane{
    Object base;
    vec3 position;
    vec3 direction;
} Plane;


Plane new_Plane(double x, double y, double z, double nx, double ny, double nz, uint8_t R, uint8_t G, uint8_t B); 

#endif