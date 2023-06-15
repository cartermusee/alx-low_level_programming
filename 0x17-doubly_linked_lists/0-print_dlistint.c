#include "lists.h"

/**
 * print_dlistint - funtion to print he elements
 * @h:pointer to list
 * Return:number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	int i = 0;
	
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}
