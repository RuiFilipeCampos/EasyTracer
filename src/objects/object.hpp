#pragma once

#include <types/geometry.hpp>
#include <properties/color.hpp>

class Object {
    protected:
        // The transformation that is being done on the object.
        double T[4][4] = {
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1}
        };

        // The inverse transformation of T, to be done on the ray.
        double invT[4][4] = {
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1}
        };

        Color color;
        bool final_form;

        Ray apply_transform(Ray *ray){

            // How do it transform the direction?

            // And how do it transform the origin?

            // c:

        };
    
    public:
        void super(){
            this->final_form = false;
        };

        void translateX(double displacement){
            this->T[0][3] += displacement;
        };

        void translateY(double displacement){
            this->T[1][3] += displacement;
        };

        void translateZ(double displacement){
            this->T[2][3] += displacement;
        };

        void lock(){ 
            this->final_form = true;

            /* calculate invT  */
        
        };
};
