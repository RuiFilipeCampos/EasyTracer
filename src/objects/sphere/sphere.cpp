#include <objects/object.hpp>
#include <objects/sphere/sphere.hpp>
#include <properties/color.hpp>


Sphere::Sphere(){};

Sphere::Sphere(double radius){
    this->super();
    this->color = BLUE;
    this->radius = radius;
};

bool Sphere::intersect(Ray *ray){
    Ray new_ray = this->apply_transform(ray);

    /* Intersection logic */

}; 
