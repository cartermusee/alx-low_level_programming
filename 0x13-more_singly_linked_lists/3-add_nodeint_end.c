#include <stdlib.h>
#include <stdio.h>
#include "lists.h"


/**
 * add_nodeint_end - function that adds a new node at the end of a listint_t
 * @head: input header pointer
 * @n: Input data int
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *neww = malloc(sizeof(listint_t));

	if (neww == NULL)
	{
		return (NULL);
	}
	neww->n = n;
	neww->next = NULL;

	if (*head == NULL)
	{
		*head = neww;
	}
	else
	{
		listint_t *p = *head;

		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = neww;
	}
	return (neww);
}
