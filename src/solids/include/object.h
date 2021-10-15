
#ifndef _OBJECTH_
#define _OBJECTH_

#include "../../../external/cglm/include/cglm/cglm.h"


typedef struct RGB{
    int R, G, B; 
} RGB;

typedef struct Object{
    void *self;
    float (*intersect)(void* self, vec3, vec3, vec3);
    float (*get_intensity)(void* self, vec3, vec3, vec3, float);
    RGB color;
} Object;



#endif