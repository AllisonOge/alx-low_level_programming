#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - add a element to the hash table
 * @ht: hash table
 * @key: key
 * @value: value associated with the key
 *
 * Return: 1 if successful otherwise 0
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int hash_index = key_index((const unsigned char *)key, ht->size);
	hash_node_t *item = malloc(sizeof(hash_node_t));

	if (!item)
		return (0);
	if (key == NULL || value == NULL)
	{
		free(item);
		return (0);
	}
	item->key = malloc(strlen(key) + 1);
	if (!item->key)
	{
		free(item);
		return (0);
	}
	item->value = malloc(strlen(value) + 1);
	if (!item->value)
	{
		free(item->key);
		free(item);
		return (0);
	}
	strcpy(item->key, key);
	strcpy(item->value, value);
	/* add item to the beginning of hash table */
	item->next = ht->array[hash_index];
	ht->array[hash_index] = item;
	return (1);
}
