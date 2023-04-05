#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - print a listint_t linked list
 * @head: pointer to head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t i, hash, len = 0;
	const listint_t *current = head;
	/* create a set to store visted nodes */
	const size_t table_size = 1024;
	const size_t hash_mask = table_size - 1;
	const listint_t **hash_table = calloc(table_size, sizeof(*hash_table));

	if (hash_table == NULL)
		exit(98);

	while (current != NULL)
	{
		/* check if the node has been visited before */
		hash = ((size_t) current) & hash_mask;
		if (hash_table[hash] == current)
		{
			printf("-> [%p] %d\n", (void *) current, current->n);
			break;
		}

		/* add the node to the hash table */
		hash_table[hash] = current;

		printf("[%p] %d\n", (void *) current, current->n);
		len++;

		current = current->next;
	}

	for(i = 0; i < table_size; i++)
		free((listint_t *) hash_table[i]);
	free(hash_table);
	return (len);
}
