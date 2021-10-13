#include <SDL2/SDL.h>
#include <cstdio>

#include <stdbool.h>

#include "../include/tracer.h"
#include "../include/types.h"




#include "../external/cglm/include/cglm/cglm.h"


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
        // printf(SDL_GetError());
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
        // printf(SDL_GetError());
        
        return -1;
    };

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if(!window_surface)
    {
        printf("Failed to get the surface of the window.");
        printf("STD Error: ");
        // printf(SDL_GetError());
        return -1;
    };

    SDL_UpdateWindowSurface(window);


    /************************************************
     *  INITIALIZING THE RAY TRACER
     * *********************************************/

    // screen is 1cm by 1cm
    Camera camera = create_simple_camera(6.8, 4.8, window_header.Nx, window_header.Ny);


    Sphere sphere = new_Sphere(0, 1.5, 15,     // center of the sphere 
                               1,            // radius of the sphere
                               0, 255, 255   // sphere color
                               );

    sphere.base.self = (void *) &sphere;


    Scene scene;
    scene.object = &(sphere.base);

    
    Plane plane = new_Plane(0, -1, 0,
                           0, 1, 0,
                         255, 255, 255);
    plane.base.self = (void *) &plane;


    Scene plane_node;
    scene.next = &plane_node;
    plane_node.object = &plane.base;

    scene.next = &plane_node; 
    plane_node.next = NULL; 






    vec3 AXIS_OF_ROTATION;



    AXIS_OF_ROTATION[0] = 0;
    AXIS_OF_ROTATION[1] = 0;
    AXIS_OF_ROTATION[2] = 1; 

    /************************************************
     *  STARTING THE EVENT LOOP 
     * *********************************************/


    SDL_Event event;

    bool keep_open = true;

    render(&camera, window_surface, &scene);
    SDL_UpdateWindowSurface(window);


    bool dragging = false;
    bool rotating = false;

    // mouse position

    typedef struct int2{
        int x, y;
    }int2;

    int2 mouse_position0;
    int2 mouse_positionf;


    while (keep_open){
        while (SDL_PollEvent(&event)){
            switch (event.type)

            {


                // MOUSE BUTTON PRESSED
                case SDL_MOUSEBUTTONDOWN:

                    switch (event.button.button)
                    {
                    case SDL_BUTTON_RIGHT:
                        dragging = true;
                        SDL_GetMouseState(&mouse_position0.x, &mouse_position0.y); 
                        break;

                    case SDL_BUTTON_LEFT:
                        rotating = true;
                        SDL_GetMouseState(&mouse_position0.x, &mouse_position0.y); 
                        break;
                    
                    default:
                        break;
                    };


                case SDL_MOUSEMOTION:
                    if (dragging){

                        SDL_GetMouseState(&mouse_positionf.x, &mouse_positionf.y);
                        sphere.center[0] += (float) (mouse_positionf.x - mouse_position0.x)/50;
                        sphere.center[1] -= (float) (mouse_positionf.y - mouse_position0.y)/50;


                        mouse_position0 = mouse_positionf;
                        render(&camera, window_surface, &scene);
                        SDL_UpdateWindowSurface(window);
                        
                    } else if (rotating) {
                        SDL_GetMouseState(&mouse_positionf.x, &mouse_positionf.y);


                        float dx = (double) (mouse_positionf.x - mouse_position0.x)/1000;

                        glm_vec3_rotate(camera.direction, -dx, camera.up);
                        glm_vec3_rotate(camera.right, -dx, camera.up);
                        







                        float dy = (double) (mouse_positionf.y - mouse_position0.y)/1000;
                        glm_vec3_rotate(camera.direction, dy, camera.right);
                        glm_vec3_rotate(camera.up, dy, camera.right);


                        // glm_vec3_rotate(camera.direction, 0.1, camera.direction);
                        // glm_vec3_rotate(camera.up, 0.1, camera.direction);
                        // glm_vec3_rotate(camera.right, 0.1, camera.direction);

                        // rotate_camera(&camera, 0 , &AXIS_OF_ROTATION); 

                        mouse_position0 = mouse_positionf;

                        render(&camera, window_surface, &scene);
                        SDL_UpdateWindowSurface(window);
                    };
                    break;

                case SDL_MOUSEBUTTONUP:
                    dragging = false;
                    rotating = false; 
                    break;


                // KEYBOARD BUTTON PRESSED
                case SDL_KEYDOWN:

                    switch (event.key.keysym.sym)
                    {
                        vec3 displacement; 

                        // CONTROLLING CAMERA (FPS LIKE)
                        case SDLK_w:
                            glm_vec3_scale(camera.direction, 0.1, displacement);
                            glm_vec3_add(camera.origin, displacement, camera.origin);
                            //camera.origin[2] += 0.1;
                            break;
                        case SDLK_s:
                            glm_vec3_scale(camera.direction, -0.1, displacement);
                            glm_vec3_add(camera.origin, displacement, camera.origin);
                            break;
                        case SDLK_a:
                            glm_vec3_scale(camera.right, -0.1, displacement);
                            glm_vec3_add(camera.origin, displacement, camera.origin);
                            break;
                        case SDLK_d:
                            glm_vec3_scale(camera.right, 0.1, displacement);
                            glm_vec3_add(camera.origin, displacement, camera.origin);
                            break;


                        // CONTROL A SPHERE 
                        case SDLK_UP:
                            sphere.center[2] += 0.1;
                            break;
                        case SDLK_DOWN:
                            sphere.center[2] -= 0.1;
                            break;
                        case SDLK_LEFT:
                            sphere.center[0] -= 0.1;
                            break;
                        case SDLK_RIGHT:
                            sphere.center[0] += 0.1;
                            break;



                    
                        default:
                            break;
                    }
                    render(&camera, window_surface, &scene);
                    SDL_UpdateWindowSurface(window);
                    break; 

                case SDL_QUIT:
                    keep_open = false;
                    break;

                
                
                default:
                    render(&camera, window_surface, &scene);
                    SDL_UpdateWindowSurface(window);
                    break; 
            };

        };


    };

    return 0;
};
