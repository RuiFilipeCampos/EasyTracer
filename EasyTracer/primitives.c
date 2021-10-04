
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

    double3 OC = subtract_vectors(_self->center,  *origin);

    double OCsq = dot_product(OC, OC);

    double c = OCsq - _self->radius * _self->radius; 
    double b = 2*dot_product(*direction, OC);
    double delta = b*b - 4*c;



    return (double) (delta > 0 & b > 2*sqrt(delta) )  ; 
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

