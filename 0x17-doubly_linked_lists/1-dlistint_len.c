#include "lists.h"

/**
 * dlistint - function to get number of elemnts
 * @h:node head
 * Return:number of elemnts
 */
size_t dlistint_len(const dlistint_t *h)
{
	int i = 0;

	while (h != NULL)
	{
		h = h->next;
		i++;
	}
	return(i);
}
