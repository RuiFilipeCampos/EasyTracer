
#include "primitives.h"
#include "types.h"






/*********
 * 
 * 
 *    SPHERES
 * 
 * 
 * ******/



double intersect_sphere(void *this, double3 *origin, double3 *direction){
    Sphere *sphere = (Sphere *) this;
    return 1; 
};

Sphere new_Sphere(double x, double y, double z, double radius){
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

    // base stuff

    sphere.base.intersect = &intersect_sphere;

    return sphere; 



};

