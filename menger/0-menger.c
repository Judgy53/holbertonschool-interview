#include <stdio.h>
#include <math.h>
#include "menger.h"


/**
 * menger - print a menger square
 * @level: level of the menger square to draw
 */
void menger(int level)
{
	int x, y, total_size, hole, square;

	/* Do nothing is level is negative */
	if (level < 0)
	{
		return;
	}
	/* Menger size is 3 ^level */
	total_size = pow(3, level);

	/* Loop through each row */
	for (y = 0; y < total_size; y++)
	{
		/* Loop through each column */
		for (x = 0; x < total_size; x++)
		{
			/* Determine if the current position in part of a hole */
			for (hole = total_size / 3; hole > 0; hole /= 3)
			{
				/* Size of the square for the current hole size */
				square = hole * 3;

				/* Check if current position is in a hole */
				if ((x % square) / hole == 1 && (y % square) / hole == 1)
				{
					putchar(' ');
					break;
				}
			}
			/* If hole <= 0, current position is not within a hole */
			if (hole <= 0)
			{
				putchar('#');
			}
		}
		putchar('\n');
	}
}
