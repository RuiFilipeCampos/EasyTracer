
#include <SDL2/SDL.h>

// a 3 dimensional vector
typedef struct double3{
	double x;
	double y;
	double z;
} double3;


// modeling a camera pixel
typedef double3 Pixel;

// modeling a screen detector as an array of pixels
typedef struct Screen{
	int Nx, Ny;     // screen size (probly bad place, but makes sense for now)
	double dx, dy; // pixel size (should this be here??)
    Pixel *start;
    Pixel *end;
} Screen;


typedef struct Camera{
	double d;         // closest distance from origin to screen
	double3 origin;   // origin of rays
	Screen screen;    // the array of detectors (Pixel)
} Camera;


Camera create_simple_camera(int Nx, int Ny);
void render(Camera *camera, SDL_Surface *surface);