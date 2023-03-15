#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * count_words - count the number of words in a string
 * @str: the string to count words in
 *
 * Return: the number of words on the string
 */
int count_words(char *str)
{
	int i, count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}

	return (count);
}
/**
 * strtow - splits a string into words
 * @str: string of words
 *
 * Return: pointer to array of words,
 * each word is null terminated if no errors or str != NULL or str != ""
 * otherwise NULL
 */
char **strtow(char *str)
{
	char **splitstr = NULL;
	int i, j, k, n_words, word_len;

	if (str == NULL || strcmp(str, "") == 0)
		return (NULL);

	n_words = count_words(str);

	splitstr = malloc(sizeof(char *) * (n_words + 1));
	if (splitstr == NULL)
		return (NULL);

	for (i = 0, j = 0; i < n_words; i++)
	{
		while (str[j] == ' ')
			j++;

		word_len = 0;
		while (str[j + word_len] != ' ' && str[j + word_len] != '\0')
			word_len++;

		splitstr[i] = malloc(sizeof(char) * (word_len + 1));
		if (splitstr[i] == NULL)
		{
			/* free previously allocated memory and return NULL */
			for (k = 0; k < i; k++)
				free(splitstr[k]);
			free(splitstr);
			return (NULL);
		}

		strncpy(splitstr[i], &str[j], word_len);
		splitstr[i][word_len] = '\0';
		j += word_len;
	}

	splitstr[n_words] = NULL;

	return (splitstr);
}
