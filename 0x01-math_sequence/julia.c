#include "mandelbrot.h"
#define MAXITER 255

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

complex plot_pixel(double i, double j, double width, 
		double height, double scale,
		double xo, double yo)
{
	complex z;

	z.re = scale * (i/width - 0.5) + xo;
	z.im = scale * (j/height - 0.5) + yo;

	/* z.re = i; */
	/* z.im = j; */

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

int main(int argc, char *argv[])
{
	FILE *fp;
	size_t xres, yres, x, y;
	complex z, c;
	double scale;
	double ypos, xpos;

	if (argc != 9)
	{
		printf("Usage: %s <xres> <yres> <scale> <xpos> <ypos> <c.real> <c.im> <filename>\n", argv[0]);
		exit(1);
	}

	xres = atoi(argv[1]);
	yres = atoi(argv[2]);

	scale = atof(argv[3]);

	xpos = atof(argv[4]);
	ypos = atof(argv[5]);

	c.re = atof(argv[6]);
	c.im = atof(argv[7]);

	fp = fopen(argv[8], "wb");

	/* initialize the pgm file */
	fprintf(fp, "P2\n");
	fprintf(fp, "%ld %ld\n", xres, yres);
	fprintf(fp, "255\n");

	for (y = 0; y < yres; y++)
	{
		for (x = 0; x < xres; x++)
		{
			z = plot_pixel(x, y, xres, yres, scale, xpos, ypos);
			fprintf(fp, "%d ", julia(z, c));
		}
		fprintf(fp, "\n");
	}

	fclose(fp);

	return (0);
}
