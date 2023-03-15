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
	size_t len1 = (s1 != NULL) ? strlen(s1) : 0;
	size_t len2 = (s2 != NULL) ? strlen(s2) : 0;

	concat = (char *) malloc(len1 + len2 + 1);
	if (concat == NULL)
		return (NULL);

	if (len1 > 0)
		strcpy(concat, s1);
	if (len2 > 0)
		strcat(concat, s2);
	return (concat);
}
