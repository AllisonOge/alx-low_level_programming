#include "lists.h"

/**
 * get_nodeint_at_index - get the nth node of a listint_t list
 * @head: pointer to the head of the node
 * @index: nth index
 *
 * Return: nth node else NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *current = head;

	while (current != NULL)
	{
		if (i == index)
			return (current);

		i++;
		current = current->next;
	}
	return (NULL);
}

