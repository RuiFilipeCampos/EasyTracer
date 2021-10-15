

#ifndef _CAMERAH_
#define _CAMERAH_

#include "../../../external/cglm/include/cglm/cglm.h"


// modeling a camera pixel
typedef vec3 Pixel;

// modeling a screen detector as an array of pixels
typedef struct Screen{
	int Nx, Ny;     // screen size (probly bad place, but makes sense for now)
	float dx, dy; // pixel size (should this be here??)
    Pixel *start;
    Pixel *end;
} Screen;


typedef struct Camera{
	float d;         // closest distance from origin to screen
	vec3 origin;   // origin of rays
	vec3 direction; //camera direction
	vec3 up;
	vec3 right;
	int halfNx, halfNy; 
	Screen screen;    // the array of detectors (Pixel)
} Camera;

Camera create_simple_camera(double X, double Y, int Nx, int Ny);


#endif