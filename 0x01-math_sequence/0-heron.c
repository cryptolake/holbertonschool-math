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

	un = malloc(sizeof(t_cell));
	if (!un)
		return (NULL);

	head = un;

	un->elt = x0;
	prev = un->elt;

	do {
		un->next = malloc(sizeof(t_cell));
		if (!un->next)
			return (NULL);

		un = un->next;
		un->elt = (1.0 / 2.0) * (prev + p / prev);
		prev = un->elt;
	} while (ABS(sqroot(p) - un->elt) > margin);

	un->next = NULL;

	return (head);
}
