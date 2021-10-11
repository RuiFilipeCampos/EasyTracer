
#include "../include/types.h"

double dot_product(double3 A, double3 B){ 
    return A.x*B.x + A.y*B.y + A.z*B.z;
    };


double3 subtract_vectors(double3 A, double3 B){ 
    double3 result;


    result.x = A.x - B.x;
    result.y = A.y - B.y;
    result.z = A.z - B.z;
    return result; 
    
    };