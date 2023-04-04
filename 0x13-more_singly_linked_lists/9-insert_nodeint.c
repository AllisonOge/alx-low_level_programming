#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - inserts a new node at a given index
 * @head: pointer to pointer to the head of the list
 * @idx: index to insert node
 * @n: value of the new node
 *
 * Return: the address of the new node or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *current = *head;
	unsigned int i = 0;

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		/* three way transaction */
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	/* move to index */
	while (current != NULL && i < idx - 1)
	{
		i++;
		current = current->next;
	}

	if (current == NULL)
		return (NULL);

	/* three way transaction */
	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}
