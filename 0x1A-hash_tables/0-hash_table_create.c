#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_create - create a hash table of a given size
 * @size: size of the table
 *
 * Return: pointer to the created table if successful otherwise NULL
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table = malloc(sizeof(hash_table_t));
	unsigned long int i;

	if (!table)
		return (NULL);
	table->size = size;
	table->array = calloc(table->size, sizeof(hash_node_t *));
	if (!table->array)
		return (NULL);
	/* set items to NULL */
	for (i = 0; i < table->size; i++)
		table->array[i] = NULL;
	return (table);
}

