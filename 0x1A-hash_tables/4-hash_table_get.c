#include "hash_tables.h"
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

	if (ht == NULL)
		return (NULL);
	hash_index = key_index((const unsigned char *)key, ht->size);
	if (ht->array[hash_index])
		return (ht->array[hash_index]->value);
	return (NULL);
}
