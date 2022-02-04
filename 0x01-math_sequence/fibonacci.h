#ifndef FIBO
#define FIBO

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
* struct t_cell - sequence linked list
* @next: next element
* @elt: value
f*
**/
typedef struct t_cell
{
	struct t_cell *next;
	int elt;

} t_cell;

t_cell *Fibonnaci();
double gold_number(t_cell *head);

#endif
