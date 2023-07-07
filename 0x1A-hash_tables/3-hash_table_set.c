#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - add or update an element to the hash table
 * @ht: hash table
 * @key: key
 * @value: value associated with the key
 *
 * Return: 1 if successful otherwise 0
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int hash_index = key_index((const unsigned char *)key, ht->size);
	hash_node_t *item, *current;

	if (ht == NULL)
		return (0);
	/* check if the key already exists in the hash table */
	current = ht->array[hash_index];
	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			/* update the value for the existing key */
			free(current->value);
			current->value = strdup(value);
			return (1);
		}
		current = current->next;
	}

	/* create a new item */
	item = create_item(key, value);
	if (!item)
		return (0);

	/* add item to the beginning of list */
	item->next = ht->array[hash_index];
	ht->array[hash_index] = item;
	return (1);
}

/**
 * create_item - create an item for the hash table
 * @key: key
 * @value: value
 *
 * Return: created item or NULL if unsuccessful
 */
hash_node_t *create_item(const char *key, const char *value)
{
	hash_node_t *item = malloc(sizeof(hash_node_t));

	if (!item)
		return (NULL);
	if (key == NULL 
		|| value == NULL || *key == '\0') /* key or value cannot be NULL */
	{
		free(item);
		return (NULL);
	}
	item->key = strdup(key);
	item->value = strdup(value);
	return (item);
}
