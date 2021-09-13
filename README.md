# EasyTracer

A ray tracer I'm building for fun.

Plan:

- build geometry in a python script
- explore the 3d environment (powered by C and the SDF library)

How it will work:

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



to do:

- [x] set up SDL https://www.libsdl.org/
- [x] opening a window
- [ ] drawing on window, pixel by pixel (possible? ->> yee)
- [ ] update selected pixels (possible?)
