#include "lists.h"

/**
 * sum_listint - sum of all the data (n) of a listint_t linked list
 * @head: pointer to the head of the list
 *
 * Return: sum of all data (n) in the list
 */
int sum_listint(listint_t *head)
{
	listint_t *current = head;
	int sum = 0;

	while (current != NULL)
	{
		sum += (int) current->n;
		current = current->next;
	}
	return (sum);
}
