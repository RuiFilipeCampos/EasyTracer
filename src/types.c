
#include "../include/types.h"

float3 float3_cast(double3 d3){
	float3 f3;
	f3.x = (float) d3.x;
	f3.y = (float) d3.y;
	f3.z = (float) d3.z;
	return f3; 
};


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