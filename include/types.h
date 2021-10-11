#ifndef _TYPESH_
#define _TYPESH_

// a 3 dimensional vector
typedef struct double3{
	double x;
	double y;
	double z;
} double3;


double dot_product(double3 A, double3 B); 


double3 subtract_vectors(double3 A, double3 B);


#endif
