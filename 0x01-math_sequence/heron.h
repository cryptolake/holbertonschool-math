#ifndef HERON
#define HERON
#include <stdio.h>
#include <stdlib.h>

/**
* struct t_cell - sequence linked list
* @next: next element
* @elt: value
*
**/
typedef struct t_cell
{
	struct t_cell *next;
	double elt;

} t_cell;

t_cell *heron(double p, double x0);

#endif
