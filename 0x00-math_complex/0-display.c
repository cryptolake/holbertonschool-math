#include "holberton.h"

void display_complex_number(complex c)
{
	printf("%.0f", c.re);
	if (c.im)
		printf(" + %.0fi", c.im);
	printf("\n");
}
