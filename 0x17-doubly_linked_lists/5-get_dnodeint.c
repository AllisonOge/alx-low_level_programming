#include "lists.h"

/**
 * get_dnodeint_at_index - get the nth node of a dlistint_t linked list
 * @head: pointer to pointer to head
 * @index: index of the node
 *
 * Return: the nth node otherwise NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;
	unsigned int i;

	if (head == NULL)
		return (NULL);

	/* transverse to the node at the specified index */
	for (i = 0; current != NULL && i < index; i++)
		current = current->next;
	return (current);
}
