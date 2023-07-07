#include "hash_tables.h"

/**
 * hash_table_print - prints elements of a hashtable
 * @ht: pointer to hashtable
 * Return: void.
 */


void hash_table_print(const hash_table_t *ht)
{
	size_t print = 0;
    hash_node_t *nod;
    unsigned long i = 0;
	

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		nod = ht->array[i];
		while (nod)
		{
			if (print)
				printf(", ");
			printf("'%s': '%s'", nod->key, nod->value);
			print++;
			nod = nod->next;
		}
	}

	printf("}\n");
}
