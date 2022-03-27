#include "holberton.h"
#include <math.h>

double modulus(complex c)
{
	return (sqrt(pow(c.im, 2) + pow(c.re, 2)));
}

complex addition(complex c1, complex c2)
{
	complex res;

	res.im = c1.im + c2.im;
	res.re = c1.re + c2.re;

	return (res);
}

complex multiplication(complex c1, complex c2)
{
	complex ca, cb, res;

	ca.re = c1.re * c2.re;
	ca.im = c1.re * c2.im;

	cb.im = c1.im * c2.re;
	cb.re = -1 * (c1.im * c2.im);

	res.re = ca.re + cb.re;
	res.im = ca.im + cb.im;

	return (res);
}
