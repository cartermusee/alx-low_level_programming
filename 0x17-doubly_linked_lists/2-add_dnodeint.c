#include "lists.h"
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


	new = malloc(sizeof(dlistint_t));
	if (!new || !head)
	{
		return (new ? free(new), NULL : NULL);
	}
	new->n = n;
	new->prev = NULL;
	if (*head == NULL)
	{
		temp = new;
		new->next = NULL;
	}
	else
	{
		new->next = temp;
		temp->prev = new;
		temp = new;
	}
	return (new);
}
