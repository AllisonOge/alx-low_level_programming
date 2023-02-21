#include <ctype.h>
/**
 * _isalpha - checks for alphabetic character
 * @c: the character to be checked
 *
 * Return: 1 if c is a letter, lowercase or uppercase
 * Otherwise 0 is returned
 */
int _isalpha(int c)
{
	if (isalpha(c))
		return (1);
	else
		return (0);
}
