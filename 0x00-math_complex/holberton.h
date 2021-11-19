#ifndef HOLBERTON_H_
#define HOLBERTON_H_
#include <stdio.h>
#include <math.h>

typedef struct complex
{
	double re;
	double im;
} complex;

void display_complex_number(complex c);
double modulus(complex c);
complex conjugate(complex c);

#endif
