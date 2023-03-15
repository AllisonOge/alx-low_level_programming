#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * argstostr - concatenates all the arguments of your program
 * @ac: number of arguments
 * @av: pointer to array of chars
 *
 * Return: NULL if ac == 0 or av == NULL otherwise a pointer to a new string
 */
char *argstostr(int ac, char **av)
{
	char *str = NULL;
	int i, j, total_len = 0;

	if (ac <= 0 || av == NULL)
		return (NULL);
	/* compute the total length of concatenated string */
	for (i = 0; i < ac; i++)
		total_len += strlen(av[i]);

	/* allocate memory for the concatenated string */
	str = (char *) malloc((total_len + ac + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);

	/* concatenate the strings */
	for (i = 0, j = 0; i < ac; i++)
	{
		strcpy(str + j, av[i]);
		j += strlen(av[i]);
		str[j++] = '\n';
	}

	str[j] = '\0';

	return (str);
}
