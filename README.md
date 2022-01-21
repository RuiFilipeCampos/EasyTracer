# EasyTracer

My second a favorite project.   

## Intro

A ray tracer I'm building for fun.

Plan:
a
- build geometry in a Lua script
- explore the 3d environment (powered by C and the SDF library)

## Current state of the project

- renders a sphere and a plane
- one isotropic point source of light
- able to move camera via "wasd" keys
- able to move sphere via arrow keys
- able to drag sphere via left mouse click + dragg


[![EasyTracer](https://yt-embed.herokuapp.com/embed?v=1Ldps3fPdyo)](https://www.youtube.com/watch?v=1Ldps3fPdyo "EasyTracer ")



## How it works:

A `Pixel` is defined as a unit vector located at some position,

```C
typedef float vec3[3] // comming from the cglm lib
typedef vec3 Pixel;
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
	vec3 origin;
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

#### Isotropic Point Light Source

```
typedef vec3 LightSource;
```

This source is entirely defined by its position in space. When the intersection point is calculated, the dot product between the surface normal and the unit vector pointing towards the source defines the intensity with which to color the pixel.


### Rotating the camera

This will likely be the hardest part.

Quaternions are obligatory I think. Cuz of their continuous rotation thing (chaining quaternions is supposed to be easy) -> https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation#The_composition_of_spatial_rotations

- [x] what does the mouse dragg input look like?
- [ ] how to turn that into ~~a math rotation thingy~~ ~~a mathematical representation of the corresponding rotation~~ a quaternion
- [ ] how to efficiently rotate thousands of unit vectors continuously ? :C
    - [ ] Can I use [SIMD](https://en.wikipedia.org/wiki/SIMD) stuff for this? 
    - [ ] https://en.wikipedia.org/wiki/OpenGL

I am now using the GPU (it's simple using the cglm lib), but I've found that rotating thousands of vectors per second is pretty much impossible, gonna look into just recreating them. 
