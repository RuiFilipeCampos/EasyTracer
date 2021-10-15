
#include "../include/render.h"




void set_pixel_color(uint8_t **window_pixel, uint8_t color){

    // R
    **window_pixel = color; // intensity is a fraction, the color val is the standard 0 to 255
    ++*window_pixel;

    // G
    **window_pixel = color;
    ++window_pixel;

    // B
    **window_pixel = color;
    ++*window_pixel;

    // alpha ??  --- not sure what this is
    // *window_pixel = 0;
    ++*window_pixel;
    
};

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

            } while(current != tot);


            if (dist == INFINITY){
                set_pixel_color(&window_pixel, 10);
                continue;
            };



            vec3 intersection_point;
            glm_vec3_scale(pixel, dist, intersection_point);
            glm_vec3_add(intersection_point, camera->origin, intersection_point); 



            Solid *solid = scene->solids[closest];

            vec3 normal;
            solid->get_normal(
                solid->self,
                intersection_point,
                normal // keeping with the cglm convention of putting the results in the last arg
            );

            vec3 to_source;



            float intensity = glm_vec3_dot(normal, to_source);

            if (intensity <= 0){
                set_pixel_color(&window_pixel, 0);
                continue;
            }
            

            /*
            if(intensity > 1){
                set_pixel_color(&window_pixel, 255);
                continue; 
            };
*/



            // R
            *window_pixel = intensity*solid->RED; // intensity is a fraction, the color val is the standard 0 to 255
            ++window_pixel;

            // G
            *window_pixel = intensity*solid->GREEN;
            ++window_pixel;

            // B
            *window_pixel = intensity*solid->BLUE;
            ++window_pixel;

            // alpha ??  --- not sure what this is
            // *window_pixel = 0;
            ++window_pixel;




        };
    };


    SDL_UnlockSurface(surface);

};