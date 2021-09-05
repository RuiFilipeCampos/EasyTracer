# EasyTracer

A ray tracer I'm building for fun.

Plan:

- build geometry in a python script
- explore the 3d environment (powered by C and the SDF library)

How it will work:


A `Pixel`struct holds the RGB values + direction information in a laboratory frame of reference:

```C
struct Pixel{
	double R;
	double G;
	double B;
	struct double3 dire; // pre-calculated directions in some original frame
};
```

A screen is an array of pixels. The camera is a struct storing the origin of the rays and some other relevant info + the screen/detector.

```
struct Camera{
	struct double3 source_point; // rays will be cast from here
	double d; 			  // distance between source and screen
	double dx;            // pixel 
	double dy;            // size
	struct Pixel *screen;        // this is shown on the actual screen
};

```


