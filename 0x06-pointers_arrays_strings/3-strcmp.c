#include "main.h"

/**
 * _strcmp - similar to strcmp
 * @s1: first string
 * @s2: last string
 * Return: 0 if equal, 15 if s1 is greater and -15 if s1 is lesser
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return ((*s1 < *s2) ? -15 : 15);
		s1++;
		s2++;
	}
	return (0);
}
