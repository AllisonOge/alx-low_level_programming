#include "function_pointers.h"
#include <stddef.h>

/**
 * print_name - prints a name
 * @name: name to print
 * @f: callback fn used to print the name
 */
void print_name(char *name, void (*f)(char *))
{
	if(f != NULL && name != NULL)
		f(name);
}
