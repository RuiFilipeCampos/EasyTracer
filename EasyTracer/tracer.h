


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
    Pixel *start;
    Pixel *end;
} Screen;



typedef struct CameraHeader{
	double d; 			  // distance between source and screen
	double dx;            // pixel 
	double dy;            // size
    int Nx;
    int Ny;
} CameraHeader;


typedef struct Camera{
	double d;         // closest distance from origin to screen
	double3 origin;   // origin of rays
	Screen screen;    // the array of detectors (Pixel)
} Camera;




Camera create_simple_camera(int Nx, int Ny);
void render(char* buffer, bool update);
