#include <stdio.h>

#include "sandpiles.h"

/**
 * print_sandpile - Print 3x3 sandpile
 * @grid: 3x3 sandpile
 */
static void print_sandpile(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (y)
				printf(" ");
			printf("%d", grid[x][y]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum_no_stabilize - computes the sum of two sandpiles
 * Doesn't stabilize the result.
 * @grid1: Left 3x3 sandpile
 * @grid2: Right 3x3 sandpile
*/
static void sandpiles_sum_no_stabilize(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			grid1[x][y] += grid2[x][y];
		}
	}
}

/**
 * stabilize_sandpile_step - topple down the sandpile once
 * @sandpile: 3x3 sandpile
 * Return: Number of cells toppled down.
*/
static int stabilize_sandpile_step(int sandpile[3][3])
{
	int x, y;
	int toppled_count = 0;
	int toppled_grains[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (sandpile[x][y] <= 3)
				continue;

			if (toppled_count == 0)
			{
				printf("=\n");
				print_sandpile(sandpile);
			}

			sandpile[x][y] -= 4;
			if (x > 0)
				toppled_grains[x - 1][y] += 1;
			if (x < 2)
				toppled_grains[x + 1][y] += 1;
			if (y > 0)
				toppled_grains[x][y - 1] += 1;
			if (y < 2)
				toppled_grains[x][y + 1] += 1;

			toppled_count += 1;
		}
	}

	sandpiles_sum_no_stabilize(sandpile, toppled_grains);
	return (toppled_count);
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: Left 3x3 sandpile
 * @grid2: Right 3x3 sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sandpiles_sum_no_stabilize(grid1, grid2);

	while (stabilize_sandpile_step(grid1))
	;
}
