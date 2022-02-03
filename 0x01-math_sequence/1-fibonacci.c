#include "fibonacci.h"
#include <math.h>
#define ABS(n) (((n) < 0) ? -(n) : (n)) /* Absolute function */

void fibo(double n1, double n2, t_cell **head)
{
	double n = n1 + n2;
	t_cell *node = *head;
	double margin = 0.0000001;

	if (ABS((n / n1) - (n1 / n2)) < margin)
	{
		node->elt = n;
		node->next = NULL;
		return;
	}

	node->elt = n;
	node->next = malloc(sizeof(t_cell));
	node = node->next;
	
	fibo(n, n1, &node);
}

t_cell *Fibonnaci()
{
	/* initialize the first two items of fibo */
	t_cell *node;

	node = malloc(sizeof(t_cell));
	fibo(1, 1, &node);

	return (node);
}

double gold_number(t_cell *head)
{
	return (head->elt / head->next->elt);
}
