#pragma once

typedef double vec3[3];

struct vec{
    double x, y, z; 
}; 

struct Ray{
    vec3 origin;
    vec3 direction; // must be normalized
};