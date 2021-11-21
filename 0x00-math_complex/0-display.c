#include "holberton.h"

void display_complex_number(complex c)
{
	printf("%g", c.re);

	if (c.im == 1 || c.im == -1)
	{
		if (c.im < 0)
			printf(" - ");
		else
			printf(" + ");
		printf("i");

	}

	else if (c.im)
	{
		if (c.im < 0)
		{
			printf(" - ");
			c.im *= -1;
		}
		else
			printf(" + ");

		printf("%gi", c.im);
	}
	printf("\n");
}
