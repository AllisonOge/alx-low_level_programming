#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to the head of the list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current = head, *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}

	head = NULL; /* set the head to NULL to indicate empty list */
}
