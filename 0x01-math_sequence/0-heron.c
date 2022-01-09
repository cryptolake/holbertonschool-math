#include "heron.h"
#define ABS(n) (((n) < 0) ? -(n) : (n)) /* Absolute function */
#define MINDIFF (2.25e-308)             /* use for convergence check */

/**
* sqroot - find sqrt of number using
* successive approximations
* @square: number
* Return: result
**/
double sqroot(double square)
{
	double root = square / 3, last, diff = 1;

	if (square <= 0)
		return (0);
	do {
		last = root;
		root = (root + square / root) / 2;
		diff = root - last;
	} while (diff > MINDIFF || diff < -MINDIFF);

	return (root);
}

/**
* heron - heron methode to estimate square root
* using heron sequence
* @p: number to estimate sqrt of
* @x0: starting number
* Return: head of linked list
**/
t_cell *heron(double p, double x0)
{
	t_cell *un, *head;
	double margin = 0.0000001;
	double prev;
	double *arr = malloc(sizeof(double));
	long int i = 0;

	un = malloc(sizeof(t_cell));
	if (!un)
		return (NULL);

	head = un;
	arr[i] = x0;
	prev = arr[i];

	do {
		i++;
		arr = realloc(arr, sizeof(double) * (i + 1));
		if (!arr)
			return (NULL);

		arr[i] = (1.0 / 2.0) * (prev + p / prev);
		prev = arr[i];
	} while (ABS(sqroot(p) - arr[i]) > margin);

	for (; i >= 0; i--) 
	{
		un->next = malloc(sizeof(t_cell));
		un = un->next;
		un->elt = arr[i];
	}
	un = NULL;

	return (head->next);
}
