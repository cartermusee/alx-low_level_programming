#include <stdio.h>
#include "lists.h"

/**
 * listint_len - function that returns the number of elements in a linked
 * listint_t list.
 *
 *
 * @h:header pointer
 *
 *
 * Return:number of elements
 */

size_t listint_len(const listint_t *h)
{
	int i = 0;

	while (h != NULL)
	{
		i++;
		h = h->next;
	}
	return (i);
}
