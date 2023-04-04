#include "lists.h"

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *node = head;

	unsigned int i = 0;

	while (i < index && node != NULL)
	{
		i++;
	}
	return (node);
}
