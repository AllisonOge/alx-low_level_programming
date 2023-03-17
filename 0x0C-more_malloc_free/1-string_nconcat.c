#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - concatenate two strings
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * @n: number of bytes concatenated
 *
 * Return: ponter to concatenated string of n bytes otherwise NULL
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int len1, len2;

	/* if s1 or s2 is NULL, treat it as an empty string */
	s1 = (s1 == NULL) ? "" : s1;
	s2 = (s2 == NULL) ? "" : s2;

	len1 = strlen(s1);
	len2 = strlen(s2);

	/* allocate memory for concat */
	if (n >= len2)
		concat = malloc(len1 + len2 + 1);
	else
		concat = malloc(len1 + n + 1);

	if (concat == NULL)
		return (NULL);
	/* copy s1 to concat */
	strcpy(concat, s1);

	/* copy n bytes of s2 to concat */
	strncat(concat, s2, n);

	/* add null terminator to the end of concat */
	concat[len1 + n] = '\0';

	return (concat);
}
