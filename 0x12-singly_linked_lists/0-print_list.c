#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_list - function that prints all the elements of a list_t list
 * @h: header pointer
 * Return: number of nodes
 */


size_t print_list(const list_t *h)
{
	size_t i = 0;

	if (h->str == NULL)
	{
		printf("[0] (nil)\n");
		h = h->next;
		i++;
	}


	while (h != NULL)
	{
		printf("[%u] %s\n", h->len, h->str);
		i++;
		h = h->next;
	}
	return (i);
}
