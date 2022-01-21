#include <iostream>
using namespace std;


namespace types{
    typedef double vec3[3];

    struct vec{
        double x, y, z; 
    }

    struct Ray{
        vec3 origin;
        vec3 direction; // must be normalized
    };
}


namespace properties{
    struct Color{
        int R, G, B; 
    }; 

    Color BLACK = {0, 0, 0};

    // le primary colors c:
    Color RED   = {255, 0, 0};
    Color GREEN = {0, 255, 0};
    Color BLUE  = {0, 0, 255};
}

#define SUPER() 


namespace primitives{
    class Object {
        private:
            double T[4][4];
            double invT[4][4];
            properties::Color color;
            bool final_form;
        
        super(){
            this->final_form = false;
            this->T = {
                {1, 0, 0, 0},
                {0, 1, 0, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 1}
            };
        }

        translateX(double displacement){
            this->T[0][3] += displacement;
        }

        translateY(double displacement){
            this->T[1][3] += displacement;
        }

        translateZ(double displacement){
            this->T[2][3] += displacement;
        }

        lock(){ 
            this->final_form = true;

            /* calculate invT  */
        
        }
    }

    class Sphere : public Object{
        private:
            types::vec3 cached_intersection;
            double radius;

        Sphere(double radius){
            this->super();
            this->color = properties::BLUE;
            this->radius = radius;
        };

        bool intersect(types::Ray *ray){
            types::Ray new_ray;
            /* apply transform on ray */

            /* Intersection logic */

        }; 
    };
}


/*
namespace operations{
    class Union{

    }; 
}


class Camera{


};

class Source{
  

}; 
*/

int main()
{

    printf("%d", properties::BLACK.R);

    Sphere *some_sphere = new Sphere(10);
    


    
    return 0;
}