#include "hash_tables.h"

/**
 * hash_table_create - creates a hashtable
 * @size: size of the hashtable
 * Return: pointer
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *item;

	if (!size)
		return (NULL);

	item = calloc(1, sizeof(hash_table_t));
	if (!item)
		return (NULL);
	item->size = size;
	item->array = calloc(size, sizeof(hash_node_t *));
	if (!item->array)
	{
		free(item);
		return (NULL);
	}
	return (item);
}
