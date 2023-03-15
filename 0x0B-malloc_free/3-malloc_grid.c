#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - pointer to 2 dimensional array of integers
 * @width: width dimension
 * @height: height dimension
 *
 * Return: pointer of array if no failure otherwise NULL
 */
int **alloc_grid(int width, int height)
{
	int i, **arr_2d = NULL;

	if (width <= 0 || height <= 0)
		return (NULL);

	arr_2d = (int **) malloc(height * sizeof(int *));
	if (arr_2d == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		arr_2d[i] = (int *) malloc(width * sizeof(int));
		if (arr_2d[i] == NULL)
			return (NULL);
	}
	return (arr_2d);
}
