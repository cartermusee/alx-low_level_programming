#include "hash_tables.h"

/**
 * hash_table_get - gets element from a hashtable
 * @ht:pointer to hashtable
 * @key:string key
 * Return: string value or NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *nod;
	unsigned long int index;

	if (!ht || !key || !*key)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	nod = ht->array[index];
	while (nod)
	{
		if (!strcmp(nod->key, key))
			return (nod->value);
		nod = nod->next;
	}
	return (NULL);
}
