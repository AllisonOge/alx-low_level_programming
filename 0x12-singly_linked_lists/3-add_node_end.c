#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node_end - add a new node to the end of a list_t list
 * @head: pointer to pointer of the head of the list
 * @str: pointer to the string data
 *
 * Return: pointer to the new node otherwise NULL
 */
list_t add_node_end(list_t **head, const char *str)
{
	list_t *current, *new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	new_node->len = strlen(str);
	new_node->next = NULL;

	current - *head;
	/* move to the end of the list */
	if (*head == NULL)
		*head = new_node;
	else
	{
		while (current->next != NULL)
			current = current->next;
		/* three way transaction */
		current->next = new_node;
	}

	return (new_node);
}
