#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * str_concat - concatenate two strings
 * @s1: pointer to first string
 * @s2: pointer to second string
 *
 * Return: pointer to concatenated string if no NULL string otherwise NULL
 */
char *str_concat(char *s1, char *s2)
{
	char *concat = NULL;

	if (s1 == NULL && s2 == NULL)
		return (NULL);

	concat = (char *) malloc(strlen(s1) + strlen(s2) + 1);
	if (concat == NULL)
		return (NULL);

	strcpy(concat, s1);
	strcat(concat, s2);
	return (concat);
}
