#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _strdup - allocates memory which contains a copy of the string
 * @str: pointer to the string
 *
 * Return: pointer to the copied string if str is not NULL otherwise NULL
 */
char *_strdup(char *str)
{
	char *dup = NULL;

	if (str == NULL)
		return (NULL);

	dup = (char *) malloc(strlen(str) + 1);

	if (dup == NULL)
		return (NULL);

	strcpy(dup, str);
	return (dup);
}
