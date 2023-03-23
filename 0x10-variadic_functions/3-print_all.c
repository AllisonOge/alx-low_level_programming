#include <stdarg.h>
#include "variadic_functions.h"
#include <stdio.h>
#include <string.h>

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

	va_start(ap, format);
	while (i < (int) strlen(format))
	{
		/* iterate over arguments and print them comma separated */
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(ap, int));
				break;
			case 'i':
				printf("%d", va_arg(ap, int));
				break;
			case 'f':
				printf("%f", va_arg(ap, double));
				break;
			case 's':
			{
				s = va_arg(ap, char *);
				if (s == NULL)
					printf("(nil)");
				else
					printf("%s", s);
				break;
			}
			default:
				/* ignore unsupported format specifiers */
				break;
		}
		/* print a comma after the argument, unless it's the last argument */
		if (i != (int)strlen(format) - 1)
			printf(", ");
		i++;
	}
	printf("\n");
	/* clean up */
	va_end(ap);
}
