

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

	struct Camera camera;

    camera.screen.Nx = Nx;
    camera.screen.Ny = Ny;

	camera.origin.x = 0;
	camera.origin.y = 0;
	camera.origin.z = 0;

	camera.screen.start = (Pixel *) malloc(Nx*Ny*sizeof(Pixel));
    camera.screen.end = camera.screen.start + Nx*Ny;


	camera.d = 10;
	camera.screen.dx = X/Nx;
	camera.screen.dy = Y/Ny;

    int halfNx = camera.screen.Nx/2;
    int halfNy = camera.screen.Ny/2;

    // should be the fastest way to iterate it
    Pixel *pixel = camera.screen.start;
    

    // CAREFUL WITH THIS
    for (int ny = 0; ny < Ny; ++ny){
        for (int nx = 0; nx < Nx; ++nx){
    
        // determine the pixels direction in this frame 
        // kinda confusing, but im modelling pixels as the direction of the rays that emanate from them

        (*pixel).z = camera.d;  // it is now touching the screen
        

        // ok, so: nx and ny are growing, so I should start at the minimum possible value of each coord
        // that be like, (-halfNX*dx, -halfNy*dy)

        (*pixel).x = ((double) (nx - halfNx) )  * camera.screen.dx;           // correct x position
        (*pixel).y = ((double) (halfNy - ny ) ) * camera.screen.dy;         // correct y position


        // normalizing the pixel
        double inv_norm = 1/sqrt( pow( (*pixel).x , 2) 
                                + pow( (*pixel).y , 2)  
                                + pow( (*pixel).z , 2) 
                                );


        (*pixel).z *= inv_norm;                    
        (*pixel).x *= inv_norm;
        (*pixel).y *= inv_norm;

        // printf("(%f, ", pixel->x);
        // printf("%f, ", pixel->y); 
        // printf("%f) \n", pixel->z); 

        ++pixel;
        };
    };

    return camera;
};


void rotate_camera(Camera *camera, double theta){

    Pixel *pixel   = camera->screen.start;


    do{
        vec3s direction = *pixel;
        // direction[0] = pixel->x;
        // direction[1] = pixel->y;
        // direction[2] = pixel->z;
        




    } while (pixel != camera->screen.end);


};


// gotta recall what is this buffer stuff
void render(Camera *camera, SDL_Surface *surface, Sphere *sphere, Plane *plane)
{
    // let's do a sphere located at z = 5 with radius of 1

                            
    Pixel *pixel   = camera->screen.start;
    SDL_LockSurface(surface);

    uint8_t *window_pixel = (uint8_t *) surface->pixels;




    double3 light_source;

    light_source.x = 0;
    light_source.y =  0.25;
    light_source.z =  15;




    do{

        
        double intensity =  sphere->base.intersect((void*)sphere, &light_source, &(camera->origin), pixel);  // this should take into account shadows and stuff
        double intensity0 =  plane->base.intersect((void*)plane, &light_source, &(camera->origin),  pixel);  // this should take into account shadows and stuff
    

        // R
        *window_pixel = intensity*sphere->base.color.R; // intensity is a fraction, the color val is the standard 0 to 255
        *window_pixel += 255*intensity0;
        ++window_pixel;

        // G
        *window_pixel = intensity*sphere->base.color.G;
        ++window_pixel;

        // B
        *window_pixel = intensity*sphere->base.color.B;
                 

        ++window_pixel;

        // alpha ??  --- not sure what this is
        // *window_pixel = 0;
        ++window_pixel;
        ++pixel;

    } while (pixel != camera->screen.end);

    SDL_UnlockSurface(surface);

};
