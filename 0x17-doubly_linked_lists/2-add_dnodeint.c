#include "list.h"
/**
 * add_dnodeint - function to add node
 * @head:head of a node
 * @n:data
 * Return:address of new element
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new, *temp;

	temp = *head;

	if (!temp)
	{
		return (NULL);
	}

	new = malloc(sizeof(dlistint_t));
	if (!new)
	{
		return (NULL);
	}
	new->n = n;
	new->prev = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (NULL);
	}
	while (temp->next)
	{
		temp->next = new;
		new->prev = temp;
		return (new);
	}
}
