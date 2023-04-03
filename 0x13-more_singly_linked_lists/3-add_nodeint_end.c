#include <stdlib.h>
#include <stdio.h>
#include "lists.h"


/**
 * add_nodeint_end - function that adds a new node at the end of a listint_t
 * @head: input header pointer
 * @int: new data
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint_end(listint_t **head, const int)
{
	listint_t *neww = malloc(sizeof(listint_t));

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
