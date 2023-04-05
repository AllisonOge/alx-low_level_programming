#include "lists.h"
#include <stdlib.h>

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the list
 *
 * Return: address fo the node wher the loop starts otherwise NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	size_t hash;
	listint_t *current = head;
	/* create a set to store visted nodes */
	size_t table_size = 1024;
	size_t hash_mask = table_size - 1;
	listint_t **hash_table = calloc(table_size, sizeof(*hash_table));

	if (hash_table == NULL)
		exit(98);

	while (current != NULL)
	{
		/* check if the node has been visited before */
		hash = ((size_t) current) & hash_mask;
		if (hash_table[hash] == current)
		{
			free(hash_table);
			return (current);
		}
		/* add node to table */
		hash_table[hash] = current;

		current = current->next;
	}

	free(hash_table);
	return (NULL);
}
