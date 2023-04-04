#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - free a listint_t list
 * @head: pointer to the head of the pointer
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
