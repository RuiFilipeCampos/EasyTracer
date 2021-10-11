#ifndef _TYPESH_
#define _TYPESH_

// a 3 dimensional vector
typedef struct double3{
	double x;
	double y;
	double z;
} double3;


typedef struct float3{
	float x;
	float y;
	float z;
} float3;

float3 float3_cast(double3 d3); 

double dot_product(double3 A, double3 B); 


double3 subtract_vectors(double3 A, double3 B);


#endif
