#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * shash_table_create - create a sorted hash table of a given size
 * @size: size of the table
 *
 * Return: pointer to the created table if successful otherwise NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = malloc(sizeof(shash_table_t));
	unsigned long int i;

	if (!ht)
		return (NULL);
	ht->size = size;
	ht->array = calloc(ht->size, sizeof(shash_node_t *));
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}
	/* set items to NULL */
	for (i = 0; i < ht->size; i++)
		ht->array[i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;
	return (ht);
}

/**
 * shash_table_set - add or update an element to the sorted hash table
 * The key/value pair should be inserted in the sorted list at the right place
 * using the ASCII value of the key
 * @ht: hash table
 * @key: key
 * @value: value associated with the key
 *
 * Return: 1 if successfull otherwise 0
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *item, *current;
	unsigned long int index;

	if (!ht)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];
	/* update the key if it already exist */
	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			return (1);
		}
		current = current->next;
	}

	/* create a new item */
	item  = create_sitem(key, value);
	if (!item)
		return (0);
	/* add item to the beginning of the list */
	item->next = ht->array[index];
	ht->array[index] = item;
	/* insert item in sorted hash table */
	return (1);
}

/**
 * create_sitem - create an item for the hash table
 * @key: key
 * @value: value
 *
 * Return: created item or NULL if unsuccessful
 */
shash_node_t *create_sitem(const char *key, const char *value)
{
	shash_node_t *item = malloc(sizeof(shash_node_t));

	if (!item)
		return (NULL);
	if (key == NULL || value == NULL
			|| *key == '\0') /* key or value cannot be NULL */
	{
		free(item);
		return (NULL);
	}
	item->key = strdup(key);
	item->value = strdup(value);
	return (item);
}
