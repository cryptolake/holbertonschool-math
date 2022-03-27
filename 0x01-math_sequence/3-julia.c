#include "holberton.h"
#define MAXITER 255


complex plot_pixel(double x, double y)
{
	complex z;

	z.re = -2 + x * 0.004;
	z.im = -2 + y * 0.004;

	return z;
}

int julia(complex z, complex c)
{
	int i;

	for (i = 0; i < MAXITER; i++)
	{
		z = addition(multiplication(z, z), c);

		if (modulus(z) > 2)
			return i;
	}

	return MAXITER;

}

void JuliaSet(FILE *name, char name1[20], complex c, int xmax, int ymax)
{
	int x, y;
	complex z;
	name = fopen(name1, "wb");

	/* initialize the pgm file */
	fprintf(name, "P2\n");
	fprintf(name, "%d %d\n", xmax, ymax);
	fprintf(name, "255\n");

	for (y = 0; y < ymax; y++)
	{
		for (x = 0; x < xmax; x++)
		{
			z = plot_pixel(x, y);
			fprintf(name, "%d ", julia(z, c));
		}
		fprintf(name, "\n");
	}

	fclose(name);

}

int main(int argc, char *argv[])
{
	FILE *fp;
	size_t xres, yres, x, y;
	complex z, c;
	double scale;
	double ypos, xpos;
	char *name;

	if (argc != 4)
	{
		printf("Usage: %s <c.real> <c.im> <filename>\n", argv[0]);
		exit(1);
	}



	c.re = atof(argv[1]);
	c.im = atof(argv[2]);
	name = argv[3];

	JuliaSet(fp, name, c, 1000, 1000);


	return (0);
}
