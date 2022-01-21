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


class Object{
    properties::Color color;

    void intersect(void){}

};


namespace primitives{

    class Sphere : Object{
        private:
            types::vec3 cached_intersection; 

        Sphere(){};

        bool intersect(types::Ray *ray){
            for (transform:){
                transform(ray);
            }; 

            /* Intersection logic */

        }; 
    };
}

namespace transforms{<

    class Translation{
        private:
            double displacement[3];

        Translation(double *vec3){
            this->displacement = vec3;
        };

        void compose(Translation *other){
            this.displacement[0] += other->displacement[0];
            this.displacement[1] += other->displacement[1];
            this.displacement[2] += other->displacement[2];
        };

        void apply(types::Ray *ray){
            (*ray).origin[0] -= this->displacement[0];
            (*ray).origin[1] -= this->displacement[1];
            (*ray).origin[2] -= this->displacement[2];
        };
    }
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