#include <ctype.h>

/**
 * _islower - checks for lowercase character
 * @c: the character to check
 *
 * Return: 1 if c is lowercase otherwise 0
 */
int _islower(char c)
{
	if (islower(c))
		return (1);
	else
		return (0);
}
