#include <iostream>
using namespace std;


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
    property::Color color;

};


namespace primitives{

    class Sphere :: Object{
        private:
            double radius;

        Sphere(double radius){
            this->radius = radius;
        }
    };
}

namespace transforms{

    // still not sure how it's going to look
    void translate(void){

    }
}


namespace operations{
    class Union{

    }; 
}


class Camera{


};

class Source{

}; 


int main()
{

    printf("%d", property::BLACK.R);
    


    
    return 0;
}