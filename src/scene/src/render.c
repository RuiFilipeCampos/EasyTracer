
#include "../include/render.h"



void render(Camera *camera, SDL_Surface *surface, Scene *scene)
{
    /*
    DESCRIPTION
        Draws scene onto screeen according to current camera parameters.
    */



    SDL_LockSurface(surface);
    uint8_t *window_pixel = (uint8_t *) surface->pixels;

    vec3 pixel;
    vec3 displacement; 

    // Iterating all pixels !
    for (int ny = 0; ny < camera->screen.Ny; ++ny){
        for (int nx = 0; nx < camera->screen.Nx; ++nx){

                    // CONSTRUCTING THE DIRECTION OF THE RAY 
                    glm_vec3_scale(
                        camera->direction,
                        camera->d, 
                        pixel
                    ); 

                    glm_vec3_add(
                        camera->origin, 
                        pixel, 
                        pixel
                    ); // it is now touching the screen

                    glm_vec3_scale(
                        camera->up, 
                        ((float) (ny - camera->halfNy  ) ) * camera->screen.dy, // up_scalar_displacement
                        displacement
                    );

                    glm_vec3_add(
                        pixel, 
                        displacement, 
                        pixel
                    );


                    glm_vec3_scale(
                        camera->right, 
                        ((float) (nx - camera->halfNx) )  * camera->screen.dx,  // right_scalar_displacement
                        displacement
                    );

                    glm_vec3_add(
                        pixel, 
                        displacement, 
                        pixel
                    );

                    glm_vec3_normalize(pixel);





                    // SHOOTING RAY

                    // Find out which solid gets intersected first, if any !
                    int tot = 10;
                    int current = 0;
                    int closest = 0; 

                    float dist;
                    float current_dist = INFINITY; 


                    do {

                        dist = scene->solids[current]->intersect(
                            scene->solids[current]->self,
                            camera->origin,
                            pixel
                        );

                        if (dist < current_dist){
                            dist = current_dist;
                            closest = current;
                        };

                        ++current; 

                    }while(current != tot);


                    if (dist == INFINITY){
                        
                        *window_pixel = 10; // intensity is a fraction, the color val is the standard 0 to 255
                        ++window_pixel;

                        // G
                        *window_pixel = 10;
                        ++window_pixel;

                        // B
                        *window_pixel = 10;
                                

                        ++window_pixel;

                        // alpha ??  --- not sure what this is
                        // *window_pixel = 0;
                        ++window_pixel;
                        continue;

                    };

                    Solid * object = scene->solids[closest];



























            

                    Scene *current_node = scene;
                    Object *closest = current_node->object;



                    float new_t0; 

                    while (current_node != NULL){
                        
                        new_t0 = current_node->object->intersect( current_node->object->self,  
                                                                light_source, 
                                                                camera->origin, 
                                                                pixel
                                                                );

                        if (new_t0 < t0){
                            closest = current_node->object;
                            t0 = new_t0;
                        };
                        current_node = current_node->next;
                    };
                    

                    float intensity; 

                    if (t0 == INFINITY){
                        *window_pixel = 10; // intensity is a fraction, the color val is the standard 0 to 255
                        ++window_pixel;

                        // G
                        *window_pixel = 10;
                        ++window_pixel;

                        // B
                        *window_pixel = 10;
                                

                        ++window_pixel;

                        // alpha ??  --- not sure what this is
                        // *window_pixel = 0;
                        ++window_pixel;
                        continue;
                    } else {

                      intensity =  closest->get_intensity(closest->self, light_source, camera->origin, pixel, t0); 

                    };


                    if (intensity > 1){

                        // R
                        *window_pixel = 255; // intensity is a fraction, the color val is the standard 0 to 255
                        ++window_pixel;

                        // G
                        *window_pixel = 255;
                        ++window_pixel;

                        // B
                        *window_pixel = 255;
                                

                        ++window_pixel;

                        // alpha ??  --- not sure what this is
                        // *window_pixel = 0;
                        ++window_pixel;
                        continue;
                    }; 

                    // R
                    *window_pixel = intensity*closest->color.R; // intensity is a fraction, the color val is the standard 0 to 255
                    //*window_pixel += 255*intensity0;
                    ++window_pixel;

                    // G
                    *window_pixel = intensity*closest->color.G;
                    ++window_pixel;

                    // B
                    *window_pixel = intensity*closest->color.B;
                            

                    ++window_pixel;

                    // alpha ??  --- not sure what this is
                    // *window_pixel = 0;
                    ++window_pixel;



        };
    };


    SDL_UnlockSurface(surface);

};