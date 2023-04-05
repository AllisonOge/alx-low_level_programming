#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - free a listint_t list
 * @h: pointer to pointer to the head of the list
 *
 * Return: size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h;
	listint_t *tmp;
	size_t len = 0;

	while (current != NULL)
	{
		len++;
		tmp = current;
		current = current->next;
		free(tmp);
		*h = NULL;

		/* check for a loop */
		if (current > current->next)
			break;
	}

	return (len);
}
