#include "holberton.h"

complex conjugate(complex c)
{
	c.im *= -1;
	return (c);
}
