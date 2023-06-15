#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes node at index
 * @head: address of ptr to head
 * @index: the index to insert
 *
 * Return: 1 on success or -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *new, *temp;

	new = *head;

	if (!head)
		return (-1);

	if (!index)
	{
		if (!new)
			return (-1);
		*head = new->next;
		if (*head)
			(*head)->prev = NULL;
		free(new);
		return (1);
	}
	for (; new; new = new->next, index--)
	{
		if (index - 1 == 0)
		{
			temp = new->next;
			if (!temp)
				break;
			new->next = temp->next;
			if (temp->next)
				temp->next->prev = new;
			free(temp);
			return (1);
		}
	}
	return (-1);
}
