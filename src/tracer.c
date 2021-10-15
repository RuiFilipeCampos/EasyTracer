#include "../external/cglm/include/cglm/cglm.h"
#include "../external/cglm/include/cglm/struct.h"

#include "../include/tracer.h"
#include "../include/primitives.h"


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <math.h>



Camera create_simple_camera(double X, double Y, int Nx, int Ny){
    /*
    PARAMETERS:
        double X: Size of screen in the world. 
        double Y: Size of screen in the world

        int Nx: Number of horizontal pixels
        int Ny: Number of vertifal pixels
    
    */

	Camera camera;

    camera.screen.Nx = Nx;
    camera.screen.Ny = Ny;

	camera.origin[0] = 0;
	camera.origin[1] = 0;
	camera.origin[2] = 0;

    camera.direction[0] = 0;
    camera.direction[1] = 0;
    camera.direction[2] = 1;

    camera.up[0] = 0;
    camera.up[1] = -1;
    camera.up[2] = 0;

    camera.right[0] = 1;
    camera.right[1] = 0;
    camera.right[2] = 0;

	camera.screen.start = (Pixel *) malloc(Nx*Ny*sizeof(Pixel));
    camera.screen.end = camera.screen.start + Nx*Ny;


	camera.d = 10;
	camera.screen.dx = X/Nx;
	camera.screen.dy = Y/Ny;

    camera.halfNx = Nx/2;
    camera.halfNy = Ny/2;
    return camera;
};




void rotate_camera(Camera *camera, double theta, vec3 *axis){
    
    return; 


};


// gotta recall what is this buffer stuff
void render(Camera *camera, SDL_Surface *surface, Scene *scene)
{
    // let's do a sphere located at z = 5 with radius of 1

                            
    // Pixel *pixel   = camera->screen.start;
    SDL_LockSurface(surface);
    uint8_t *window_pixel = (uint8_t *) surface->pixels;


    vec3 light_source;
    light_source[0] = 0;
    light_source[1] =  0.25;
    light_source[2] =  15;

    vec3 pixel;



    // CAREFUL WITH THIS
    for (int ny = 0; ny < camera->screen.Ny; ++ny){
        for (int nx = 0; nx < camera->screen.Nx; ++nx){
                
                    // CONSTRUCTING THE PIXEL 
                    glm_vec3_scale(camera->direction, camera->d, pixel); 
                    glm_vec3_add(camera->origin, pixel, pixel); // it is now touching the screen
                    float up_scalar_displacement = ((float) (ny - camera->halfNy  ) ) * camera->screen.dy;  
                    vec3 displacement; 
                    glm_vec3_scale(camera->up, up_scalar_displacement, displacement);
                    glm_vec3_add(pixel, displacement, pixel);
                    float right_scalar_displacement = ((float) (nx - camera->halfNx) )  * camera->screen.dx; 
                    glm_vec3_scale(camera->right, right_scalar_displacement, displacement);
                    glm_vec3_add(pixel, displacement, pixel);
                    glm_vec3_normalize(pixel);


                    // SHOOTING RAY

            

                    Scene *current_node = scene;
                    Object *closest = current_node->object;


                    float t0 = current_node->object->intersect(   current_node->object->self,  
                                                                light_source, 
                                                                camera->origin, 
                                                                pixel
                                                                );
                    float new_t0; 

                    while (current_node != NULL){
                        
                        new_t0 = current_node->object->intersect( current_node->object->self,  
                                                                light_source, 
                                                                camera->origin, 
                                                                pixel
                                                                );

                        if (new_t0 < t0){
                            closest = current_node->object;
                            t0 = new_t0;
                        };
                        current_node = current_node->next;
                    };
                    

                    float intensity; 

                    if (t0 == INFINITY){
                        *window_pixel = 10; // intensity is a fraction, the color val is the standard 0 to 255
                        ++window_pixel;

                        // G
                        *window_pixel = 10;
                        ++window_pixel;

                        // B
                        *window_pixel = 10;
                                

                        ++window_pixel;

                        // alpha ??  --- not sure what this is
                        // *window_pixel = 0;
                        ++window_pixel;
                        continue;
                    } else {

                      intensity =  closest->get_intensity(closest->self, light_source, camera->origin, pixel, t0); 

                    };


                    if (intensity > 1){

                        // R
                        *window_pixel = 255; // intensity is a fraction, the color val is the standard 0 to 255
                        ++window_pixel;

                        // G
                        *window_pixel = 255;
                        ++window_pixel;

                        // B
                        *window_pixel = 255;
                                

                        ++window_pixel;

                        // alpha ??  --- not sure what this is
                        // *window_pixel = 0;
                        ++window_pixel;
                        continue;
                    }; 

                    // R
                    *window_pixel = intensity*closest->color.R; // intensity is a fraction, the color val is the standard 0 to 255
                    //*window_pixel += 255*intensity0;
                    ++window_pixel;

                    // G
                    *window_pixel = intensity*closest->color.G;
                    ++window_pixel;

                    // B
                    *window_pixel = intensity*closest->color.B;
                            

                    ++window_pixel;

                    // alpha ??  --- not sure what this is
                    // *window_pixel = 0;
                    ++window_pixel;



        };
    };


    SDL_UnlockSurface(surface);

};
