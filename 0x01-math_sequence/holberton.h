#ifndef HOLBERTON_H_
#define HOLBERTON_H_

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
double modulus(complex c);


#endif
