#include "holberton.h"
void multiplication(complex c1, complex c2, complex *c3)
{
	complex ca, cb;

	ca.re = c1.re * c2.re;
	ca.im = c1.re * c2.im;

	cb.im = c1.im * c2.re;
	cb.re = -1 * (c1.im * c2.im);

	c3->re = ca.re + cb.re;
	c3->im = ca.im + cb.im;
}
