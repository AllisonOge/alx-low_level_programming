#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - add a new node at the end of a listint_t list
 * @head: pointer to the pointer of the head of the list
 * @n: value of the list
 *
 * Return: address of the new node or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *current = *head;

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	/* move to the end of the list */
	if (current == NULL)
		*head = new_node;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	return (new_node);
}
