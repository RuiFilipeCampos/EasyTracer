


#include "./object.h"


typedef struct Sphere{
    Object base;
    vec3 center;
    float radius;
} Sphere;

Sphere new_Sphere(double x, double y, double z, double radius, uint8_t R, uint8_t G, uint8_t B);
