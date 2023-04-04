#include "lists.h"

/**
 * sum_listint - function that returns the sum of all the data  of a listint_t
 *@head: pointer to list
 * Return: if the list is empty, return 0
 */

int sum_listint(listint_t *head)
{
	listint_t *ct = head;

	int sum = 0;

	if (head == NULL)
	{
		return (0);
	}
	while (ct != NULL)
	{
		sum += ct->n;
		ct = ct->next;
	}
	return (sum);
}
