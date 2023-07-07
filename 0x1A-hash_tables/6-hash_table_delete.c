#include "hash_tables.h"

/**
 * hash_table_delete - deletes hashtable
 * @ht: pointer to hashtable
 * Return: void.
 */
void hash_table_delete(hash_table_t *ht)
{
	
	hash_node_t *nod, *tmp;
	unsigned long i = 0;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		nod = ht->array[i];
		while (nod)
		{
			tmp = nod;
			nod = nod->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
	}
	free(ht->array);
	free(ht);
}
