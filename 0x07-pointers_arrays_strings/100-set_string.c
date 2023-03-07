#include "main.h"

/**
 * set_string - sets the valude of a pointer to a char
 * @s: pointer to a pointer to a string
 * @to: pointer to a string
 */
void set_string(char **s, char *to)
{
	*s = to;
}
