


#include "tracer.h"
#include "primitives.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <math.h>



double dot_product(double3 A, double3 B){ return A.x*B.x + A.y*B.y + A.z* };





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


    // fastest way to iterate it
    Pixel *pixel = camera.screen.start;




    int nx, ny; // not sure if this will be faster cuz of these
    int i = 0; // counting iterations 

    while (pixel != camera.screen.end){

        nx = i % Ny;
        ny = i % Nx;

    // 5 x 2
        // 0 1 2 3 4 5 6 7 8 9 10

        // 0 1 2 3 4
        // 5 6 7 8 9

        // determine the pixels direction in this frame 
        // kinda confusing, but im modelling pixels as the direction of the rays that emanate from them


        (*pixel).z = camera.d;                               // it is now touching the screen
        (*pixel).x = (halfNx + nx)*camera.screen.dx;
        (*pixel).y = (halfNy + ny)*camera.screen.dy;

        double inv_norm = 1/sqrt( pow( (*pixel).dire.x, 2) + pow( (*pixel).dire.y, 2)  + pow( (*pixel).dire.z, 2) );
        (*pixel).z *= inv_norm;                     // it is now touching the screen
        (*pixel).x *= inv_norm;
        (*pixel).y *= inv_norm;


        ++pixel;
        ++i;


    };

    double inv_norm;
    int nx, ny; 

	for (nx = 0; nx < Nx; ++nx){
		for (ny = 0; ny < Ny; ++ny){

            // determine the pixels direction in this frame 
            // kinda confusing, but im modelling pixels as the direction of the rays that emanate from them
            (*pixel).z = camera.d;                               // it is now touching the screen
            (*pixel).x = (halfNx + nx)*camera.screen.dx;
            (*pixel).y = (halfNy + ny)*camera.screen.dy;

            inv_norm = 1/sqrt( pow( (*pixel).x, 2) + pow( (*pixel).y, 2)  + pow( (*pixel).z, 2) );

            (*pixel).z *= inv_norm;                     // it is now touching the screen
            (*pixel).x *= inv_norm;
            (*pixel).y *= inv_norm;   

            ++pixel;
		};
	};

    return camera;

};






void render(Camera *camera, char* buffer)
{
    Pixel *pixel = camera->screen.start; 
    
    // let's do a sphere located at z = 5 with radius of 1
    Sphere sphere;
    sphere.center.x = 0; 
    sphere.center.y = 0; 
    sphere.center.z = 5;
    sphere.radius   = 1; 


    double3 origin = camera->source_point;


    double a, b, c;


    while (pixel != camera->screen.end){

        
        b = 2 * pixel->dire * () ;
        c = ; 

        // no intersection --> branch can easily be removed 
        if (b*b - 4*c < 0){
            pixel->R = 255;
            pixel->G = 255;
            pixel->B = 255;
            ++pixel; continue; 
        } else{
            pixel->R = 0;
            pixel->G = 0;
            pixel->B = 0;
            ++pixel; continue;
        };

        printf("ERROR: NEITHER INTERSECTION NOR NO INTERSECTION WAS CHOSEN"); 
        
    };

};
