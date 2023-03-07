#include "main.h"
#include <string.h>

/**
 * _strstr - locates a substring
 * @haystack: pointer to string to be searched
 * @needle: pointer to substring to be located
 *
 * Return: pointer to the first occurence of the substring in the string
 * Otherwise NULL
 */
char *_strstr(char *haystack, char *needle)
{
	return (strstr(haystack, needle));
}
