#ifndef _TRACERH_
#define _TRACERH_

#include <SDL2/SDL.h>

#include "primitives.h"
#include "types.h"
#include "../external/cglm/include/cglm/cglm.h"

struct Object; 
struct Sphere; 
struct Plane;


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



typedef struct Scene{
	Object* object;
	Scene* next;
}Scene;


Camera create_simple_camera(double X, double Y, int Nx, int Ny); 
void render(Camera *camera, SDL_Surface *surface, Scene *scene);
void rotate_camera(Camera *camera, double theta, vec3 *axis);


typedef struct LightSource{
	vec3 direction;
	vec3 position;
}LightSource;


#endif