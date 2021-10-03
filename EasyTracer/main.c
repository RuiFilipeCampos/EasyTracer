#include <SDL2/SDL.h>
#include <cstdio>

#include <stdbool.h>


#include "tracer.h"



struct WindowHeader{
    int Nx, Ny;  // size of window in pixels
};

int main( int argc, char **argv )
{
    /************************************************
     *  INITIALIZING SDL AND OPENING A WINDOW
     * *********************************************/

    // SDL_Init() returns 0 on success and a negative number on failure.
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Failed to initialize `SDL`.");
        printf("STD Error: ");
        printf(SDL_GetError());
        return -1;
    };

    struct WindowHeader window_header;
    window_header.Nx = 680;
    window_header.Ny = 480;

    // creating a window 
    SDL_Window *window = SDL_CreateWindow("SDL2 Window", // the title 
                                          SDL_WINDOWPOS_CENTERED, // x position 
                                          SDL_WINDOWPOS_CENTERED, // y position
                                          window_header.Nx, window_header.Ny, // size of window 
                                          0);  // wuts this ??


    if(!window)
    {

        printf("Failed to create window.");
        printf("STD Error: ");
        printf(SDL_GetError());
        
        return -1;
    };

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if(!window_surface)
    {
        printf("Failed to get the surface of the window.");
        printf("STD Error: ");
        printf(SDL_GetError());
        return -1;
    };

    SDL_UpdateWindowSurface(window);


    /************************************************
     *  INITIALIZING THE RAY TRACER
     * *********************************************/

    Camera camera = create_simple_camera(6.8, 4.8, window_header.Nx, window_header.Ny);


    /************************************************
     *  STARTING THE EVENT LOOP 
     * *********************************************/


    SDL_Event event;

    bool keep_open = true;

    render(&camera, window_surface);
    SDL_UpdateWindowSurface(window);

    while (keep_open){
        while (SDL_PollEvent(&event)){
            switch (event.type)
            {
                case SDL_QUIT:
                    keep_open = false;
                    break;
                
                default:
                    continue; // the default should be this thing
                    // rendering will occur on user input 
            };

        };


    };

    return 0;
};
