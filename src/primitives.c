
#include "../include/primitives.h"
#include "../include/types.h"
#include "../include/tracer.h"



#include <stdio.h>
#include <math.h>

#include <stdint.h>


/*********
 * 
 * 
 *    SPHERES
 * 
 * 
 * ******/


void normalize(double3* vector){
    
    double inverse_norm;
    inverse_norm = 1/sqrt(vector->x*vector->x + vector->y*vector->y + vector->z*vector->z);

    vector->x *= inverse_norm;
    vector->y *= inverse_norm;
    vector->z *= inverse_norm;


};


float intersect_sphere(void *self, vec3 light_source, vec3 camera_origin, vec3 pixel){
    // not letting me use the name `this`. gonna use 'self' 
    Sphere *sphere = (Sphere *) self;

    vec3 OC;
    glm_vec3_sub(camera_origin, sphere->center, OC);


    float c = glm_vec3_norm2(OC) - sphere->radius * sphere->radius;  // can be optimized
    float b = 2*glm_vec3_dot(pixel, OC);
    float delta = b*b - 4*c;

    if (delta >= 0){

        // printf("Intersected \n");


        double t1 = (-b - sqrt(delta))/2;
        // printf("dist = %f; ", t1); 

        if (t1 > 0){

            // where is the nearest intersection ? 
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
            
            if (intensity <= 0){ return 0.01; };
    
            return intensity/glm_vec3_distance2(intersection_point, light_source);

        };
    };

    return 0; 


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

    Sphere sphere;

    // geometric parameters
    sphere.center[0] = x;
    sphere.center[1] = y;
    sphere.center[2] = z;
    sphere.radius = radius;

    sphere.base.color.R = R;
    sphere.base.color.G = G;
    sphere.base.color.B = B; 

    // base stuff

    sphere.base.intersect = &intersect_sphere;
    return sphere; 



};





float intersect_plane(void *self, vec3 light_source, vec3 camera_origin, vec3 pixel){

    Plane *plane = (Plane*) self;

    float ln = glm_vec3_dot(plane->direction, pixel);
    if (ln == 0){return 0; }


    vec3 result;
    glm_vec3_sub(plane->position, light_source, result);
    double t0 = glm_vec3_dot(result, plane->direction) / ln;
    
    
    /*double t0 = dot_product(
        subtract_vectors(plane->position, *light_source),
        plane->direction
    ) / ln;
*/

    if (t0 < 0){return 0;};


    
    // where is the nearest intersection ? 
    vec3 intersection_point;
    glm_vec3_scale(pixel, t0, intersection_point);
    glm_vec3_add(intersection_point, camera_origin, intersection_point);

    /*
    intersection_point.x = camera_origin->x + t0*pixel->x;
    intersection_point.y = camera_origin->y + t0*pixel->y;
    intersection_point.z = camera_origin->z + t0*pixel->z;
    */

    // from intersection to source
    vec3 intersection_source;
    glm_vec3_sub(light_source, intersection_point, intersection_source); 
    /*
    intersection_source.x = light_source->x - intersection_point.x;
    intersection_source.y = light_source->y - intersection_point.y;
    intersection_source.z = light_source->z - intersection_point.z;*/

    glm_vec3_normalize(intersection_source);
    // normalize(&intersection_source);


    return glm_vec3_dot(intersection_source, plane->direction); 


}; 




Plane new_Plane(double x, double y, double z, double nx, double ny, double nz, uint8_t R, uint8_t G, uint8_t B){
    /*
    PARAMETERS:

    */

    Plane plane;

    // geometric parameters
    plane.position[0] = x;
    plane.position[1] = y;
    plane.position[2] = z;

    plane.direction[0] = nx;
    plane.direction[1] = ny;
    plane.direction[2] = nz;

    // color
    plane.base.color.R = R;
    plane.base.color.G = G;
    plane.base.color.B = B; 

    // base stuff

    plane.base.intersect = &intersect_plane;
    return plane; 



};


