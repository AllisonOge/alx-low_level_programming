#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - add a new node at the end of a dlistint_t list
 * @head: pointer to a pointer to the head
 * @n: data of the new node
 *
 * Return: address of the new node
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *current;

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;

	current = *head;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
	} else
	{
		while (current->next != NULL)
			current = current->next;
		new->prev = current;
		current->next = new;
	}
	return (new);
}
