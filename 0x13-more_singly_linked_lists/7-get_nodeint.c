#include "lists.h"

/**
 * get_nodeint_at_index - function that returns the nth node of a listint_t
 * @index: the index of the node
 * @head: pointer to the list
 * Return: return NULL if no node
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *node = head;

	unsigned int i = 0;

	while (i < index && node != NULL)
	{
		i++;
		node = node->next;
	}
	return (node);
}
