#include "lists.h"
#include <stdlib.h>


/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t
 * linked list
 * @head: pointer to pointer to head
 * @index: index of the node to be deleted
 *
 * Return: 1 if it succeeds otherwise -1
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head, *prev;
	unsigned int i;

	if (*head == NULL)
		return (-1);
	/* tranverse to the node at the specified index */
	for (i = 0; current != NULL && i < index; i++)
	{
		prev = current;
		current = current->next;
	}

	if (current == NULL)
		return (-1);

	if (prev != NULL)
		prev->next = current->next;
	else
		*head = current->next; /* if deleting the head node */

	if (current->next != NULL)
		current->next->prev = prev;
	free(current);
	return (1);
}
