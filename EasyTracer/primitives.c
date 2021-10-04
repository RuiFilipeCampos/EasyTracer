
#include "primitives.h"
#include "types.h"

#include <math.h>

#include <stdint.h>


/*********
 * 
 * 
 *    SPHERES
 * 
 * 
 * ******/





double intersect_sphere(void *self, double3 *origin, double3 *direction){
    // not letting me use the name `this`. gonna use 'self' 
    Sphere *_self = (Sphere *) self;

    double3 OC = subtract_vectors(_self->center,  *origin); // don't like having a function call here
    //double OCsq = dot_product(OC, OC);

    double c = dot_product(OC, OC) - _self->radius * _self->radius;  // can be optimized
    double b = 2*dot_product(*direction, OC);
    double delta = b*b - 4*c;


    if ( (delta > 0 & b > 2*sqrt(delta)) ){ 
        
        double t1 = -b - 2*sqrt(delta);

        double3 intersection_point;

        intersection_point.x = origin->x + direction->x*t1;
        intersection_point.y = origin->y + direction->y*t1;
        intersection_point.z = origin->z + direction->z*t1;

        

        return 1;
        
        }; // le first branch appears


    return 0;


};

Sphere new_Sphere(double x, double y, double z, double radius, uint8_t R, uint8_t G, uint8_t B){
    /*
    PARAMETERS:
        COORDINATES OF THE CENTER OF THE SPHERE (cm):
            double x
            double y
            double z

        double radius: radius of sphere in cm
    */

    Sphere sphere;

    // geometric parameters
    sphere.center.x = x;
    sphere.center.y = y;
    sphere.center.z = z;
    sphere.radius = radius;

    sphere.base.color.R = R;
    sphere.base.color.G = G;
    sphere.base.color.B = B; 

    // base stuff

    sphere.base.intersect = &intersect_sphere;
    return sphere; 



};

