#include <iostream>
using namespace std;


namespace property{
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


namespace primitive{

    class Sphere :: Object{
        private:
            double radius;

        Sphere(double radius){
            this->radius = radius;
        }
    };
}

namespace transform{

    // still not sure how it's going to look
    void translate(void){

    }
}


namespace operation{
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