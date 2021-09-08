


// a 3 dimensional vector
typedef struct double3{
	double x;
	double y;
	double z;
} double3;


// modeling a camera pixel
typedef struct Pixel{
	int R, G, B;
    double3 dire;
} Pixel;



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




// modelling the camera
typedef struct Camera{
	double d; 			  // distance between source and screen
	double dx;            // pixel 
	double dy;            // size
    int Nx;
    int Ny;
    CameraHeader HEADER;
	double3 source_point; // rays will be cast from here
	Screen screen;        // this is shown on the actual screen
} Camera;

Camera create_simple_camera(int Nx, int Ny);


void render(char* buffer, bool update);
