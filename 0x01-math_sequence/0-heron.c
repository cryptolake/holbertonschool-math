#include "heron.h"
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
	double margin = pow(10, -7);
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
	} while (fabs(sqrt(p) - un->elt) > margin);

	un->next = NULL;

	return (head);
}
