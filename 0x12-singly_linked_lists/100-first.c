#include <stdio.h>

void my_init_func(void) __attribute__((constructor));

/**
 * my_init_func - prints message before the main function
 */
void my_init_func(void)
{
	printf(
			"You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}
