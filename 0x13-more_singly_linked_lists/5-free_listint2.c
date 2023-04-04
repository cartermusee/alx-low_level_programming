#include "lists.h"
#include <stdlib.h>
/**
 * free_listint2 - frees a list of ints
 * @head: address of pointer to first node
 *
 *
 * Return: void
 */


void free_listint2(listint_t **head)
{
	listint_t *ct;

	if (head == NULL)
	{
		return;
	}

	while (*head != NULL)
	{
		ct = *head;
		*head = (*head)->next;
		free(ct);
	}
	*head = NULL;
}

