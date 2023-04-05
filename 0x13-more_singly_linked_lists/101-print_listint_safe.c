#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - print a listint_t linked list
 * @head: pointer to head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;
	size_t len = 0;

	while (current != NULL)
	{
		printf("[%p] %d\n", (void *) current, current->n);
		len++;

		/* chech for a loop */
		if (current > current->next)
		{
			printf("-> [%p] %d\n", (void *) current->next, current->next->n);
			break;
		}
		current = current->next;
	}

	return (len);
}
