#include "mandelbrot.h"
#define MAXITER 255


int color(int iter)
{
		return iter;
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

int mandelbrot(complex c)
{
	complex f;
	int i;

	for (i = 0; i < MAXITER; i++)
	{
		f = addition(multiplication(f, f), c);

		if (absf(f.re) > 2)
			return i;
	}

	return MAXITER;

}

int main(int argc, char *argv[])
{
	FILE *fp;
	size_t xres, yres, x, y;
	complex c;
	double scale;
	double ypos, xpos;

	if (argc != 7)
	{
		printf("Usage: %s <xres> <yres> <scale> <xpos> <ypos> <filename>\n", argv[0]);
		exit(1);
	}

	xres = atoi(argv[1]);
	yres = atoi(argv[2]);

	scale = atof(argv[3]);

	xpos = atof(argv[4]);
	ypos = atof(argv[5]);

	fp = fopen(argv[6], "wb");

	/* initialize the pgm file */
	fprintf(fp, "P2\n");
	fprintf(fp, "%d %d\n", xres, yres);
	fprintf(fp, "255\n");

	for (y = 0; y < yres; y++)
	{
		for (x = 0; x < xres; x++)
		{
			c = plot_pixel(x, y, xres, yres, scale, xpos, ypos);
			fprintf(fp, "%d ", color(mandelbrot(c)));
		}
		fprintf(fp, "\n");
	}

	fclose(fp);

	return (0);
}
