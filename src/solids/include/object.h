
#ifndef _SOLIDH_
#define _SOLIDH_

#include "../../../external/cglm/include/cglm/cglm.h"


typedef struct RGB{
    int R, G, B; 
} RGB;

typedef struct Solid{
    void *self;
    float (*intersect)(void* self, vec3, vec3, vec3);
    float (*get_intensity)(void* self, vec3, vec3, vec3, float);
    int RED, GREEN, BLUE; 
} Solid;



#endif