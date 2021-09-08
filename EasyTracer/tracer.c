


#include "tracer.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



Camera create_simple_camera(int Nx, int Ny){

	struct Camera camera;

    camera.Nx = Nx;
    camera.Ny = Ny;

	camera.source_point.x = 0;
	camera.source_point.y = 0;
	camera.source_point.z = 0;

	camera.screen.start = (struct Pixel *) malloc(Nx*Ny*sizeof(Pixel));
    camera.screen.end = camera.screen.start + Nx + Ny; 

	camera.d = 1;
	camera.dx = camera.d/4;
	camera.dy = camera.d/4;

    Pixel *pixel = camera.screen.start;

    int halfNx = camera.Nx - camera.Nx / 2;
    int halfNy = camera.Ny - camera.Ny / 2; 

	for (int nx = 0; nx < Nx; ++nx){
		for (int ny = 0; ny < Ny; ++ny){
            
			// determine the pixels direction in this frame
			(*pixel).dire.z = camera.d;                     // it is now touching the screen
			(*pixel).dire.x = (halfNx + nx)*camera.dx;   
			(*pixel).dire.y = (halfNy + ny)*camera.dy;

			(*pixel).R = 0;
			(*pixel).G = 0;
			(*pixel).B = 0;
            
            ++pixel;
		};
	};



    return camera;

};


typedef struct Sphere{
    double3 center;
    double radius;
} Sphere;

void render(Camera *camera, char* buffer)
{
    Pixel *pixel = camera->screen.start; 
    
    // let's do a sphere located at z = 5 with radius of 1
    Sphere sphere;
    sphere.center.x = 0; 
    sphere.center.y = 0; 
    sphere.center.z = 5;
    sphere.radius = 1; 


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
