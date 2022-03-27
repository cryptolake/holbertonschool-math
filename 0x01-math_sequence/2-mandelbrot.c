#include "holberton.h"
#define MAXITER 255

complex plot_pixel(double x, double y, double width,
		double height, double scale)
{
	complex z;

	z.re = (x - width/2) * scale / width;
	z.im = (y - height/2) * scale / height;

	return z;
}

int mandelbrot(complex c)
{
	complex f;
	int i;

	for (i = 0; i < MAXITER; i++)
	{
		f = addition(multiplication(f, f), c);

		if (fabs(f.re) > 2)
			return i;
	}

	return MAXITER;

}

int main(void)
{
	FILE *fp;
	size_t xres, yres, x, y;
	complex c;
	double scale;


	xres = 1000;
	yres = 1000;

	scale = 4;

	fp = fopen("mandelbrot.pgm", "wb");

	/* initialize the pgm file */
	fprintf(fp, "P2\n");
	fprintf(fp, "%ld %ld\n", xres, yres);
	fprintf(fp, "255\n");

	for (y = 1; y <= yres; y++)
	{
		for (x = 1; x <= xres; x++)
		{
			c = plot_pixel(x, y, xres, yres, scale);
			fprintf(fp, "%d ", mandelbrot(c));
		}
		fprintf(fp, "\n");
	}

	fclose(fp);

	return (0);
}
