#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of memory to print
 * @size: the size of the memory to print
 *
 * Return: Nothing.
 */
void simple_print_buffer(char *buffer, unsigned int size)
{
    unsigned int i;

    i = 0;
    while (i < size)
    {
        if (i % 10)
        {
            printf(" ");
        }
        if (!(i % 10) && i)
        {
            printf("\n");
        }
        printf("0x%02x", buffer[i]);
        i++;
    }
    printf("\n");
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
/*    char *c;
    int *i;
    float *f;
    double *d;

    c = malloc_checked(sizeof(char) * 1024);
    printf("%p\n", (void *)c);
    i = malloc_checked(sizeof(int) * 402);
    printf("%p\n", (void *)i);
    f = malloc_checked(sizeof(float) * 100000000);
    printf("%p\n", (void *)f);
    d = malloc_checked(INT_MAX);
    printf("%p\n", (void *)d);
    free(c);
    free(i);
    free(f);
    free(d); */
/*    char *concat;

    concat = string_nconcat("Best ", "School !!!", 6);
    printf("%s\n", concat);
    free(concat); */
/*    int *a;

    a = array_range(0, 10);
    simple_print_buffer(a, 11);
    free(a); */
    char *p;
    int i;

    p = malloc(sizeof(char) * 10);
    p = _realloc(p, sizeof(char) * 10, sizeof(char) * 98);
    i = 0;
    while (i < 98)
    {
        p[i++] = 98;
    }
    simple_print_buffer(p, 98);
    free(p);
    return (0);
}
