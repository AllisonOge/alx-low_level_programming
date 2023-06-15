#include "lists.h"

/**
 * dlistint_len - get the number of elements in a dlistint_t list
 * @h: pointer to the head of list
 *
 * Return: return the number of elements in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t n = 0;

	while (h != NULL)
	{
		h = h->next;
		n++;
	}
	return (n);
}
