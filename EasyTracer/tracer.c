


#include "tracer.h"
#include "primitives.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <math.h>



double dot_product(double3 A, double3 B){ return A.x*B.x + A.y*B.y + A.z*B.z; };
double3 minus(double3 A, double3 B){ 
    double3 result;

    result.x = A.x - B.x;
    result.y = A.y - B.y;
    result.z = A.z - B.z;
    return result; 
    
    };






Camera create_simple_camera(int Nx, int Ny){
    // for now only the screen size is passed

    // ok, I should have constructors for these
	struct Camera camera;

    camera.screen.Nx = Nx;
    camera.screen.Ny = Ny;

	camera.origin.x = 0;
	camera.origin.y = 0;
	camera.origin.z = 0;

	camera.screen.start = (Pixel *) malloc(Nx*Ny*sizeof(Pixel));
    camera.screen.end = camera.screen.start + Nx*Ny; 


	camera.d = 1;

    double size = 0.1;
	camera.screen.dx = size;
	camera.screen.dy = size;

    int halfNx = camera.screen.Nx/2;
    int halfNy = camera.screen.Ny/2;

    // should be the fastest way to iterate it
    Pixel *pixel = camera.screen.start;

    
    for (int nx = 0; nx < Nx; ++nx){
        for (int ny = 0; ny < Ny; ++ny){
    
        // determine the pixels direction in this frame 
        // kinda confusing, but im modelling pixels as the direction of the rays that emanate from them



        (*pixel).z = camera.d;  // it is now touching the screen
        

        // ok, so: nx and ny are growing, so I should start at the minimum possible value of each coord
        // that be like, (-halfNX*dx, -halfNy*dy)

        (*pixel).x = ((double) (nx - halfNx))  * camera.screen.dx;           // correct x position
        (*pixel).y = ((double) (ny - halfNy))  * camera.screen.dy;           // correct y position

        


        // normalizing the pixel
        double inv_norm = 1/sqrt( pow((*pixel).x, 2) + pow((*pixel).y, 2)  + pow((*pixel).z, 2) );

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




// gotta recall what is this buffer stuff
void render(Camera *camera, SDL_Surface *surface)
{
    
    // let's do a sphere located at z = 5 with radius of 1
    Sphere sphere;
    sphere.center.x = 0; 
    sphere.center.y = 0; 
    sphere.center.z = 5;
    sphere.radius   = 2;

    double3 origin = camera->origin;
    Pixel *pixel = camera->screen.start;

    SDL_LockSurface(surface);

    // printf("surface->h = %d", surface->h);
    // printf("surface->pitch = %d", surface->pitch);

    // SDL_memset(surface->pixels, 255, surface->h * surface->pitch);

    uint8_t *window_pixel = (uint8_t *) surface->pixels ;
    uint8_t intersected;




    double b, c;

    double3 OC; 
    OC = minus(sphere.center,  camera->origin);
    double OCsq = dot_product(OC, OC);
    c = OCsq - sphere.radius*sphere.radius; 


    while (pixel != camera->screen.end){
        
        //b = 2 * pixel->dire * () ;
        // c = ;
        

        b = 2*dot_product(*pixel, OC);
        intersected =  255*( (uint8_t) (b*b - 4*c > 0) ) ;

       // printf("(%d, ", pixel->x);
       // printf("%d, ", pixel->y); 
       // printf("%d) \n", pixel->z); 


        
        

        // R
        *window_pixel = intersected;
        ++window_pixel;

        // G
        *window_pixel = intersected;
        ++window_pixel;

        // B
        *window_pixel = intersected;
        ++window_pixel;

        // alpha ??  --- not sure what this is
        // *window_pixel = 0;
        ++window_pixel;
    

        ++pixel;

    };

    SDL_UnlockSurface(surface);

};
