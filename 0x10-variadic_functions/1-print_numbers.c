#include <stdarg.h>
#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_numbers - prints number followed by a new line
 * @separator: delimiter for the numbers
 * @n: number of integers to be passed to the fn
 * @...: integers
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;

	/* initialize the arg list */
	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		/* iterate over arg in list */
		if (separator == NULL)
			break;
		if (i == n - 1)
			printf("%d", va_arg(ap, int));
		else
			printf("%d%s", va_arg(ap, int), separator);
	}
	printf("\n");
	/* clean up */
	va_end(ap);
}
