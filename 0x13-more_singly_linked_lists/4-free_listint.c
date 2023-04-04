#include <stdio.h>
#include "lists.h"
#include <stdlib.h>

/**
 *free_listint - frees a list of ints
 *@head: pointer to first node
 *Return: void
 */

void free_listint(listint_t *head)
{
	listint_t *temp = head;

	while (temp != NULL)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
}
