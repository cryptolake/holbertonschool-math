#ifndef MANDELBROT
#define MANDELBROT
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct complex
{
	double re;
	double im;
} complex;

complex multiplication(complex c1, complex c2);
complex addition(complex c1, complex c2);

#endif
