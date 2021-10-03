


#include "tracer.h"
#include "primitives.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <math.h>



double dot_product(double3 A, double3 B){ return A.x*B.x + A.y*B.y + A.z*B.z; };





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
	camera.screen.dx = camera.d/4;
	camera.screen.dy = camera.d/4;

    int halfNx = camera.screen.Nx - camera.screen.Nx / 2;
    int halfNy = camera.screen.Ny - camera.screen.Ny / 2;

    // should be the fastest way to iterate it
    Pixel *pixel = camera.screen.start;
    int nx, ny;                             // not sure if this will be faster cuz of these
    int i = 0;                              // counting iterations 
    double inv_norm; 

    while (pixel != camera.screen.end){
        /* 
        // I think this will be faster, at least this time, I don't need to store these values
        // nx = i % Ny;
        // ny = i % Nx;

        // 5 x 2
        // 0 1 2 3 4 5 6 7 8 9 10

        // 0 1 2 3 4
        // 5 6 7 8 9
        */

        // determine the pixels direction in this frame 
        // kinda confusing, but im modelling pixels as the direction of the rays that emanate from them
        (*pixel).z = camera.d;                                     // vector is now touching the screen
        (*pixel).x = (halfNx + i % Ny)*camera.screen.dx;           // correct x position
        (*pixel).y = (halfNy + i % Nx)*camera.screen.dy;           // correct y position




        // normalizing the pixel
        inv_norm = 1/sqrt( pow( (*pixel).x, 2) + pow( (*pixel).y, 2)  + pow( (*pixel).z, 2) );

        (*pixel).z *= inv_norm;                     // it is now touching the screen
        (*pixel).x *= inv_norm;
        (*pixel).y *= inv_norm;

        ++pixel;
        ++i;
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
    sphere.radius   = 1;


    double3 origin = camera->origin;
    double a, b, c;
    Pixel *pixel = camera->screen.start; 

    bool intersected;


    SDL_LockSurface(surface);

    printf("surface->h = %d", surface->h);
    printf("surface->pitch = %d", surface->pitch);

    SDL_memset(surface->pixels, 255, surface->h * surface->pitch);


    while (pixel != camera->screen.end){
        
        //b = 2 * pixel->dire * () ;
        // c = ;


        // intersected = b*b - 4*c < 0;
        
        intersected = true; 
        ++pixel;

    };

    SDL_UnlockSurface(surface);

};
