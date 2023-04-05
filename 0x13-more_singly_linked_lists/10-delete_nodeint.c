#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - delete the nth node of a listint_t list
 * @head: pointer to pointer to the head of the list
 * @index: index
 *
 * Return: 1 if successful otherwise -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t **current = head;
	listint_t *temp;
	unsigned int i = 0;

	/* move to index */
	while (*current != NULL && i < index)
	{
		current = &(*current)->next;
		i++;
	}

	if (*current == NULL)
		return (-1);

	temp = *current;
	*current = (*current)->next;
	free(temp);
	return (1);
}
