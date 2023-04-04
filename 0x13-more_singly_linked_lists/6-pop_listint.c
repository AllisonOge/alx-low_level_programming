#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - delete the head node of a listint_t list
 * @head: pointer to pointer to the head of the list
 *
 * Return: data of the new head
 */
int pop_listint(listint_t **head)
{
	listint_t *current = *head;
	int n;

	if (current == NULL)
		return (0);
	/* delete the head */
	*head = (*head)->next;
	n = current->n;
	free(current);
	return (n);
}
