#include "lists.h"

/**
 * reverse_listint - function which reverses a listint_t
 * @head: pointer to pointer to head of list
 * Return: pointer to head of new list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *node, *temp1, *temp2;
	
	node = *head;
	temp1 = NULL;
	temp2 = NULL;

	while (node !=  NULL)
	{
		temp2 = node->next;
		node->next = temp1;
		temp1 = node;
		node = temp2;
	}
	*head = temp1;
	return (*head);
}
