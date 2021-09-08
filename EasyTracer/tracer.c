#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// a 3-tuple
typedef struct double3{
	double x;
	double y;
	double z;
} double3;


typedef struct RGBPixel{
	int R, G, B;
    double3 dire;
} RGBPixel;


typedef struct Camera{
	struct double3 source_point; // rays will be cast from here
	double d; 			  // distance between source and screen
	double dx;            // pixel 
	double dy;            // size
	struct Pixel *screen;        // this is shown on the actual screen
} Camera;






void render(char* buffer, bool update)
{

	// construct the simplest camera
	int Nx = 50;
	int Ny = 50;

	struct Camera camera;

	camera.source_point.x = 0;
	camera.source_point.y = 0;
	camera.source_point.z = 0;


	camera.screen = (struct Pixel *) malloc(Nx*Ny*sizeof(struct Pixel));

	camera.d = 1;
	camera.dx = camera.d/4;
	camera.dy = camera.d/4;

	for (int nx = 0; nx < Nx; ++nx){
		for (int ny = 0; ny < Ny; ++ny){
			struct Pixel *pixel = camera.screen + Nx + Ny;

			// determine the pixels direction in this frame
			(*pixel).dire.z = camera.d;              // it is now touching the screen
			(*pixel).dire.x = nx*camera.dx;   
			(*pixel).dire.y = ny*camera.dy;

			(*pixel).R = 0;
			(*pixel).G = 0;
			(*pixel).B = 0;
		};
	};



	printf("\n PRINTING SCREEN \n ");

	//HBITMAP bit_map = CreateBitmap(Nx, Ny, 1, sizeof(int));


	for (int nx = 0; nx < Nx; ++nx){
		printf("\n");

		for (int ny = 0; ny < Ny; ++ny){
			struct Pixel *pixel = camera.screen + Nx + Ny;

		    printf(" (%d) ", pixel->R);


		};
	};

	return 0;
};