#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2D grid created with alloc_grid
 * @grid: 2D grid
 * @height: height dimension
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
}
