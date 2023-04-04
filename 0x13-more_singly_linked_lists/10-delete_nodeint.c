#include "lists.h"

/**
 * delete_nodeint_at_index-function that deletes the node at index
 * @head: pointer to a pointer to the head node of the list
 *
 * @index: index of the position of the node to be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */


int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *node, *tmp;

	unsigned int i;

	if  (index == 0 && *head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		return (1);
	}
	node = *head;

	for (i = 0; i < index - 1 && node != NULL; i++)
	{
		node = node->next;
	}
	if (node == NULL || node->next == NULL)
	{
		return (-1);
	}
	 tmp = node->next;
	 node->next = tmp->next;
	 free(tmp);

	return (1);
}
