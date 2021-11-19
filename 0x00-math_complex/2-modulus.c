#include "holberton.h"


double modulus(complex c)
{
	return (sqrt(pow(c.im, 2) + pow(c.re, 2)));
}
