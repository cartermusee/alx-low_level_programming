#include "hash_tables.h"

/**
 * new_node - funcition for new node
 * @key: the key
 * @value: the value
 * Return: the node or NULL
 */
hash_node_t *new_node(const char *key, const char *value)
{
	hash_node_t *nod;

	nod = calloc(1, sizeof(hash_node_t));
	if (nod == NULL)
		return (0);

	nod->key = strdup(key);
	if (!nod->key)
	{
		free(nod);
		return (0);
	}
	nod->value = strdup(value);
	if (!nod->value)
	{
		free(nod->key);
		free(nod);
		return (0);
	}

	return (nod);
}


/**
 * hash_table_set - function to add element to a hashtable
 * @ht: pointer to hashtable
 * @key: the key
 * @value: the value
 * Return: 1  success, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *nod = NULL, *tmp;
	unsigned long int id;

	if (!ht || !key || !*key || !value)
		return (0);

	id = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[id];
	while (tmp)
	{
		if (!strcmp(key, tmp->key))
		{
			char *_value = strdup(value);

			if (!_value)
				return (0);
			free(tmp->value);
			tmp->value = _value;
			return (1);
		}
		tmp = tmp->next;
	}
	nod = new_node(key, value);
	if (!nod)
		return (0);
	nod->next = ht->array[id];
	ht->array[id] = nod;
	return (1);
}
