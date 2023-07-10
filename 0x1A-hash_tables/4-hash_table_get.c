#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: hast table
 * @key: key
 *
 * Return: value of the associated key or NULL if key couldn't be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int hash_index;
	hash_node_t *current;

	if (ht == NULL)
		return (NULL);
	hash_index = key_index((const unsigned char *)key, ht->size);
	if (ht->array[hash_index])
	{
		if (strcmp(key, ht->array[hash_index]->key) == 0)
		{
			return (ht->array[hash_index]->value);
		}
		else
		{
			current = ht->array[hash_index];
			while (current)
			{
				if (strcmp(key, current->key) == 0)
					return (current->value);
				current = current->next;
			}
		}
	}
	return (NULL);
}
