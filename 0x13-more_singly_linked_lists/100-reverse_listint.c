#include "lists.h"

/**
 * reverse_listint - reverse a listint_t linked list
 * @head: pointer to pointer to the head of the list
 *
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head;

	while (current != NULL)
	{
		*head = current->next;	/* update head to the next node */
		current->next = prev;	/* reverse the link of the current node */
		prev = current;	/* move prev to the current node */
		current = *head;	/* move current to the next node */
	}

	/* set the head pointer to the last node (previously the tail)*/
	*head = prev;
	return (*head);
}
