#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts node at  index
 * @h: address ptr to head
 * @idx: the index to insert
 * @n:the value of the inserted
 * Return: new node or NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *tmp;

	tmp = *h;
	if (!h)
	{
		return (NULL);
	}
	new = malloc(sizeof(dlistint_t));
	if (!new)
	{
		return (NULL);
	}
	new->n = n;
	if (!idx)
	{
		new->prev = NULL;
		new->next = tmp ? tmp : NULL;
		if (tmp)
			tmp->prev = new;
		return (*h = new);
	}
	for (; tmp; tmp = tmp->next, idx--)
	{
		if (idx - 1 == 0)
		{
			new->prev = tmp;
			new->next = tmp->next;
			if (new->next)
				new->next->prev = new;
			tmp->next = new;
			return (new);
		}
	}
	return (free(new), NULL);
}
