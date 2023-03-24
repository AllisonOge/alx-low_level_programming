#include <stdarg.h>
#include "variadic_functions.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * print_all - prints anything (char, int, float, char *)
 * @format: list of types of argument passed to the func
 * @...: arguments
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int i = 0;
	char *s;
	bool ignore = false;

	va_start(ap, format);
	while (format && i < (int) strlen(format))
	{
		/* iterate over arguments and print them comma separated */
		switch (format[i])
		{
			case 'c':
				ignore = false;
				printf("%c", va_arg(ap, int));
				break;
			case 'i':
				ignore = false;
				printf("%d", va_arg(ap, int));
				break;
			case 'f':
				ignore = false;
				printf("%f", va_arg(ap, double));
				break;
			case 's':
			{
				ignore = false;
				s = va_arg(ap, char *);
				if (s == NULL)
					s = "(nil)";
				printf("%s", s);
				break;
			}
			default:
				/* ignore unsupported format specifiers */
				ignore = true;
				break;
		}
		/* print a comma after the argument, unless it's the last argument */
		if (i != (int)strlen(format) - 1 && !ignore)
			printf(", ");
		i++;
	}
	printf("\n");
	/* clean up */
	va_end(ap);
}
