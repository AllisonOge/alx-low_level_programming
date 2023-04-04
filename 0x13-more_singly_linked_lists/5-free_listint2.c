#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - free a listint_t list and set head to NULL
 * @head: pointer to pointer to the head of the list
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	while (*head != NULL)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
	}
}
