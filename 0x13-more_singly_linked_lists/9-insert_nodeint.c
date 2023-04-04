#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 *
 * @head: pointer to a pointer to the head node of the list
 *
 * @idx: index of the position where the new node should be inserted
 * @n: value to be stored in the new node
 *
 * Return:the address of the new node, or NULL if it failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *old;

	unsigned int k;

	new = malloc(sizeof(listint_t));

	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	old = *head;
	for (k = 0; k < idx - 1 && old != NULL; k++)
	{
		old = old->next;
	}
	if (old == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = old->next;
	old->next = new;

	return (new);
}
