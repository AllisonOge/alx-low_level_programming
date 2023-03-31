#include "lists.h"
#include <stdio.h>

/**
 * print_list - prints the elements of a list_t list
 * @h: linked list to be printed
 *
 * Return: the number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t len = 0;
	const list_t *current = h;

	while (current != NULL)
	{
		if (current->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", current->len, current->str);
		len++;
		current = current->next;
	}

	return (len);
}
