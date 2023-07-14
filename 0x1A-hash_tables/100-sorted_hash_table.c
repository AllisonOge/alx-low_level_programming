#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
	item = create_sitem(key, value);
	if (!item)
		return (0);
	/* add the item to the hash table */
	item->next = ht->array[index];
	ht->array[index] = item;
	/* add the item to the sorted list */
	if (ht->shead == NULL)
	{
		ht->shead = item;
		ht->stail = item;
	}
	else if (strcmp(item->key, ht->shead->key) < 0)
	{
		item->snext = ht->shead;
		ht->shead->sprev = item;
		ht->shead = item;
	}
	else if (strcmp(item->key, ht->stail->key) > 0)
	{
		item->sprev = ht->stail;
		ht->stail->snext = item;
		ht->stail = item;
	}
	else
	{
		current = ht->shead;
		while (current->snext && strcmp(item->key, current->snext->key) > 0)
			current = current->snext;
		item->sprev = current;
		item->snext = current->snext;
		current->snext->sprev = item;
		current->snext = item;
	}
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

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: hash table
 * @key: key
 *
 * Return: value of the associated key or NULL if key couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current;

	if (!ht)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];
	while (current)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

/**
 * shash_table_print - print the sorted hash table
 * @ht: hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;

	if (!ht)
		return;
	current = ht->shead;
	printf("{");
	while (current)
	{
		printf("'%s': '%s'", current->key, current->value);
		if (current->snext)
			printf(", ");
		current = current->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - print the sorted hash table in reverse order
 * @ht: hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;

	if (!ht)
		return;
	current = ht->stail;
	printf("{");
	while (current)
	{
		printf("'%s': '%s'", current->key, current->value);
		if (current->sprev)
			printf(", ");
		current = current->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *item;
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
		while (ht->array[i])
		{
			item = ht->array[i];
			ht->array[i] = ht->array[i]->next;
			free(item->key);
			free(item->value);
			free(item);
		}
	free(ht->array);
	free(ht);
}
