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
double argument(complex c);
void addition(complex c1, complex c2, complex *c3);
void substraction(complex c1, complex c2, complex *c3);
void multiplication(complex c1, complex c2, complex *c3);
void division(complex c1, complex c2, complex *c3);
#endif
