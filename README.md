# EasyTracer

My second a favorite project.

## Intro

A ray tracer I'm building for fun.

Plan:

- build geometry in a Lua script
- explore the 3d environment (powered by C and the SDF library)

## Current state of the project

[![EasyTracer](https://yt-embed.herokuapp.com/embed?v=EuKUWbwAnW0)](https://www.youtube.com/watch?v=EuKUWbwAnW0 "EasyTracer ")



## How it works:

A `Pixel` is defined as a unit vector located at some position,

```C
typedef struct double3{
    double x, y, z;
}double3;

typedef double3 Pixel;
```

The position is not included in the codes definition of `Pixel` because that quantity will later be implicitly defined by the `Camera`'s parameters.

A screen is an array of pixels,

```C
typdef struct Screen{
    double dx, dy; // the size of a pixel
    Pixel *start;  // the start of the array
    Pixel *end;    // the end of the array
}Screen;

Screen screen;

screen.start = (Pixel*) malloc(sizeof(Pixel)*Nx*Ny);
screen.end = screen.start + Nx*Ny;
```

The 'true' array is dynamically allocated since the actual size of the screen is user defined (unknowable to the compiler).

The `Camera` is a struct storing the origin of the rays, the shortest distance between the origin and the screen, the screen itself and the

```C
struct Camera{
	double d;
	double3 origin;
	Screen screen;
};
```

Rays originate from `camera.origin` with direction defined by each `Pixel` in the `Screen`.

> `camera.d` might be useless, `d` is only used for constructing the screen


## Tasks 
### Constructing the Camera (done)

to do:

- [x] set up SDL https://www.libsdl.org/
- [x] opening a window
- [x] drawing on window, pixel by pixel (possible? ->> yee)
- [x] update selected pixels (possible?)

### Shadows

#### Light source

It makes sense for light sources to be a position + unit vector (a ray basically). 

```C
typdef struct LightSource{
	double3 position;
	double3 direction;
};
```

To save time I think the unit vector should point away from where the light is being shined. The algo itself should be something like

- get the position of the intersection
- check that the ray  `position_of_intersection + light_source.direction` does not hit anything
    - IF TRUE: add 0 to pixel
    - IF FALSE
        - calculate normal vector to that position in the sphere
        - calculate the dot product -> that's the value to add to the pixel   

- [ ] light source
- [ ] include calculation of normal vecs at a pos

### Rotating the camera

This will likely be the hardest part.

Quaternions are obligatory I think. Cuz of their continuous rotation thing (chaining quaternions is supposed to be easy) -> https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation#The_composition_of_spatial_rotations

- [ ] what does the mouse dragg input look like?
- [ ] how to turn that into ~~a math rotation thingy~~ ~~a mathematical representation of the corresponding rotation~~ a quaternion
- [ ] how to efficiently rotate thousands of unit vectors continuously ? :C
    - [ ] Can I use [SIMD](https://en.wikipedia.org/wiki/SIMD) stuff for this? 
    - [ ] https://en.wikipedia.org/wiki/OpenGL
