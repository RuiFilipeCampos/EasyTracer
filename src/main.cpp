#include <iostream>
using namespace std;


namespace structures{
    namespace lists{

        template <T>
        class Node{
            T content;
            Node *next;
        }

        template <T>
        class SinglyLinkedList{
            public:
                Node<T> head;

            SinglyLinkedList(T first_element){
                this->head.content = first_element;
                this->head.next = NULL;
            }
            
            append(){};
        }
    }
}

namespace types{
    typedef double vec3[3];

    struct vec{
        double x, y, z; 
    }; 

    struct Ray{
        vec3 origin;
        vec3 direction; // must be normalized
    };
};


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


namespace primitives{
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
            double invT[4][4] {
                {1, 0, 0, 0},
                {0, 1, 0, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 1}
            };

            properties::Color color;
            bool final_form;

            types::Ray apply_transform(types::Ray *ray){

                // How do it transform the direction?

                // And how do it transform the origin?

                // c:

            };
        
        public:
            void super(){
                this->final_form = false;
            }

            void translateX(double displacement){
                this->T[0][3] += displacement;
            }

            void translateY(double displacement){
                this->T[1][3] += displacement;
            }

            void translateZ(double displacement){
                this->T[2][3] += displacement;
            }

            void lock(){ 
                this->final_form = true;

                /* calculate invT  */
            
            }
    };


    class Sphere : public Object{
        private:
            types::vec3 cached_intersection;
            double radius;
        public:
            Sphere(double radius){
                this->super();
                this->color = properties::BLUE;
                this->radius = radius;
            };

            // this shall return some relevant data structure
            // which shall be determined later when thinking about
            // them interval arithmetics
            bool intersect(types::Ray *ray){
                types::Ray new_ray = this->apply_transform(ray);

                /* Intersection logic */

            }; 
    };
}



int main()
{

    printf("%d", properties::BLACK.R);

    primitives::Sphere *some_sphere = new primitives::Sphere(10);
    some_sphere->translateX(1);
    some_sphere->translateY(-1);
    some_sphere->lock();

    return 0;
}