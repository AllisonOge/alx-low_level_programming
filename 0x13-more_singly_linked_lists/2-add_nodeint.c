#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - add a new node at the beginning of a listint_t list
 * @head: pointer to pointer of the head of the list
 * @n: value of the node
 *
 * Return: address of the new element, or NULL if failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	/* three way transaction */
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}
