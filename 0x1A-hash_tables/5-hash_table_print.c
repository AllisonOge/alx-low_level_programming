#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - prints a hash table
 * @ht: hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;

	if (!ht)
		return; /* if NULL print nothing */
	printf("{");
	for (i = 0; i < (ht->size - 1); i++)
		if (ht->array[i])
			printf("'%s': '%s',", ht->array[i]->key, ht->array[i]->value);
	if (ht->array[i])
		printf("'%s': '%s'", ht->array[i]->key, ht->array[i]->value);
	printf("}\n");
}
