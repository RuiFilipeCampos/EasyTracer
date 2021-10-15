
#include "../include/camera.h"



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