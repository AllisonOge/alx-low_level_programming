#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node - add a new node to the beginning of a list_t list
 * @head: pointer to pointer of the list
 * @str: pointer to the string data
 *
 * Return: pointer to the new node otherwise NULL
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	new_node->len = strlen(str);

	/* three way transaction */
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
