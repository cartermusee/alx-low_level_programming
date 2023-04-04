#include <stdio.h>
#include "lists.h"


/**
 * pop_listint - function that deletes head of a node
 * @head: pointer to pointer to the first node of the list
 *
 *
 *
 * Return: the data of the head node, or 0 if the list is empty
 */

int pop_listint(listint_t **head)
{
	listint_t *ct;

	int n;

	if (head == NULL || *head == NULL)
	{
		return (0);
	}

	ct = *head;
	n = (*head)->n;
	*head = (*head)->next;
	free(ct);
	return (n);
}


