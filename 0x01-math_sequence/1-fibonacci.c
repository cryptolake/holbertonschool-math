#include "fibonacci.h"
#include <math.h>
#include <stdlib.h>
#define ABS(n) (((n) < 0) ? -(n) : (n)) /* Absolute function */

/**
 * fibo - the Fibonacci sequence recusively until achieving the
 * golden ratio with error code of 10^-7
 *
 * @n1: first element
 * @n2: second element
 * @node: linked list
 *
 **/
void fibo(double n1, double n2, t_cell **node)
{
	double n = n1 + n2;
	double margin = 0.0000001;

	if (ABS((n / n1) - (n1 / n2)) <= margin)
	{
		(*node)->elt = (int) n;
		(*node)->next = malloc(sizeof(t_cell));
		*node = (*node)->next;
		return;
	}

	fibo(n, n1, node);

	(*node)->elt = (int) n;
	(*node)->next = malloc(sizeof(t_cell));
	*node = (*node)->next;
}

/**
 * Fibonacci - the Fibonacci sequence recusively until achieving the
 * golden ratio with error code of 10^-7
 *
 * Return: linked list.
 **/
t_cell *Fibonnaci()
{
	/* initialize the first two items of fibo */
	t_cell *head, *node = malloc(sizeof(t_cell));

	head = node;

	fibo(1, 1, &node);
	node->elt = 1;
	node->next = malloc(sizeof(t_cell));
	node->next->elt = 1;
	node->next->next = NULL;

	return (head);
}

/**
 * gold_number - calculate gold number form fibonacci
 * sequence
 * @head: head of linked list
 *
 * Return: golden number
 **/
double gold_number(t_cell *head)
{
	return ((double)head->elt / (double)head->next->elt);
}
