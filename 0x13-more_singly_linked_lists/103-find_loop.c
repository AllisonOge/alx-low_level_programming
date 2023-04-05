#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the list
 *
 * Return: address fo the node wher the loop starts otherwise NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *current = head;

	while (current != NULL)
	{
		current = current->next;
		
		/* check for a loop */
		if (current > current->next)
			return (current->next);
	}

	return (NULL);
}
