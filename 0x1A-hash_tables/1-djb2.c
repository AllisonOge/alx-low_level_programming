#include "hash_tables.h"

/**
 * hash_djb2 - hash function
 * @str: string
 *
 * Return: 32 bit hash code
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int c;

	while ((c = *str++))
		hash = hash * 33 + c; /* hash * 33 + c */

	return (hash);
}
