


#include "../include/sphere.h"

#include <stdio.h>
#include <math.h>
#include <stdint.h>








float intersect_sphere(void *self, vec3 light_source, vec3 camera_origin, vec3 pixel){
    
    Sphere *sphere = (Sphere *) self;

    vec3 OC;
    glm_vec3_sub(camera_origin, sphere->center, OC);


    float c = glm_vec3_norm2(OC) - sphere->radius * sphere->radius;  // can be optimized
    float b = 2*glm_vec3_dot(pixel, OC);
    float delta = b*b - 4*c;

    if (delta >= 0){
        double t1 = (-b - sqrt(delta))/2;
        if (t1 > 0){ return t1;};
    };

    return INFINITY; 
};



float get_intensity_sphere(void * self, vec3 light_source, vec3 camera_origin, vec3 pixel, float t1){
            Sphere *sphere = (Sphere *) self;

            vec3 intersection_point;
            glm_vec3_scale(pixel, t1, intersection_point);
            glm_vec3_add(intersection_point, camera_origin, intersection_point); 


            // from intersection to source
            vec3 intersection_source;
            glm_vec3_sub(light_source, intersection_point, intersection_source);
            glm_vec3_normalize(intersection_source);


            // normal to sphere = from center to intersection
            vec3 center_intersection;
            glm_vec3_sub(intersection_point, sphere->center, center_intersection);
            glm_vec3_normalize(center_intersection);


            float intensity = glm_vec3_dot(center_intersection, intersection_source); 
            
            if (intensity <= 0){ return 0.005; };
    
            return intensity/glm_vec3_distance2(intersection_point, light_source);

};



// Soil 

Sphere new_Sphere(double x, double y, double z, double radius, uint8_t R, uint8_t G, uint8_t B){
    /*
    PARAMETERS:
        COORDINATES OF THE CENTER OF THE SPHERE (cm):
            double x
            double y
            double z

        double radius: radius of sphere in cm
    */


    // INITIALIZING OBJECT
    Sphere sphere;

    // METHODS
    sphere.base.intersect = &intersect_sphere;
    sphere.base.get_intensity = &get_intensity_sphere;


    // BASE ATTRIBUTES
    sphere.base.color.R = R;
    sphere.base.color.G = G;
    sphere.base.color.B = B;

    // SUBCLASS ATTRIBUTES
    sphere.center[0] = x;
    sphere.center[1] = y;
    sphere.center[2] = z;
    sphere.radius = radius;





    // base stuff

    return sphere; 



};
