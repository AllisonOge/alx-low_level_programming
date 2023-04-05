#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - free a listint_t list
 * @h: pointer to pointer to the head of the list
 *
 * Return: size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	size_t hash, len = 0;
	listint_t *tmp, *current = *h;
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
			break;

		/* add node to table */
		hash_table[hash] = current;

		len++;
		tmp = current;
		current = current->next;
		free(tmp);
		*h = NULL;
	}

	free(hash_table);
	return (len);
}
