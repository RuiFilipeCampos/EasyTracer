
#include "../include/plane.h"

#include <stdio.h>
#include <math.h>
#include <stdint.h>




float intersect_plane(void *self, vec3 light_source, vec3 camera_origin, vec3 pixel){

    Plane *plane = (Plane*) self;

    float ln = glm_vec3_dot(plane->direction, pixel);
    if (ln == 0){return INFINITY; }


    vec3 result;
    glm_vec3_sub(plane->position, light_source, result);
    double t0 = glm_vec3_dot(result, plane->direction) / ln;
    
    
    /*double t0 = dot_product(
        subtract_vectors(plane->position, *light_source),
        plane->direction
    ) / ln;
*/

    if (t0 < 0){return INFINITY;};

    return t0;


    



}; 

float get_intensity_plane(void * self, vec3 light_source, vec3 camera_origin, vec3 pixel, float t0){
    Plane *plane = (Plane*) self;

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


    return glm_vec3_dot(intersection_source, plane->direction)/glm_vec3_distance2(light_source, intersection_point);

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
    plane.base.get_intensity = &get_intensity_plane; 
    return plane; 



};


