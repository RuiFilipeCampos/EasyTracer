#pragma once



#include <objects/object.hpp>
#include <objects/object.hpp>
#include <objects/sphere/sphere.hpp>

#include <types/geometry.hpp>

class Sphere : public Object{
    private:
        vec3 cached_intersection;
        double radius;

    public:
        Sphere();
        Sphere(double radius);
        bool intersect(Ray *ray);
};