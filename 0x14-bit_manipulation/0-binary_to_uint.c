#include "main.h"
#include <stddef.h>
#include <string.h>

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number or 0 if b is NULL
 * or b is invalid
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int dec, len;
	int i;

	if (!b)
		return (0);

	dec = 0;
	for (i = 0; i < (int)len; i++)
	{
		if (b[i] == '0' || b[i] == '1')
		{
			if (b[i] == '1')
				dec |= (1u << (len - i - 1));
		} else
			return (0);
	}
	return (dec);
}
