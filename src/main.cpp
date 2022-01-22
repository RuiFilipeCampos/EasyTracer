#include <iostream>
#include "data/lists/singly_linked_list.hpp"
#include "objects/sphere/sphere.hpp"

using namespace std;


int main()
{

    // printf("%d", BLACK.R);

    Sphere *some_sphere = new Sphere(10);
    some_sphere->translateX(1);
    some_sphere->translateY(-1);
    some_sphere->lock();

    // simple stuff for now 
    Sphere *first_sphere = new Sphere(10);
    first_sphere->translateZ(10);
    first_sphere->lock();
    SinglyLinkedList<Sphere> scene = SinglyLinkedList<Sphere>(
        *first_sphere
    );

    return 0;
}