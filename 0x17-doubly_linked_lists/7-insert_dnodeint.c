#include "lists.h"
#include <stdlib.h>


/**
 * insert_dnodeint_at_index - inserts a new node at a given index
 * @h: pointer to pointer to head
 * @idx: index of the list where the new node should be added
 * @n: data of the node
 *
 * Return: address of the new node otherwise NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current = *h, *prev = NULL;
	dlistint_t *new = malloc(sizeof(dlistint_t));
	unsigned int i;

	if (!new)
		return (NULL);
	/* transverse to the node at the specific index */
	for (i = 0; current != NULL && i < idx; i++)
	{
		prev = current;
		current = current->next;
	}

	if (current == NULL)
		return (NULL);

	new->n = n;
	new->prev = prev;
	new->next = current;
	current->prev = new;
	if (prev != NULL)
		prev->next = new;
	else
		*h = new;
	return (new);
}
