#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

/**
 * try_merge - tries to merge two cell of the array
 * @line: array of number
 * @slow: index of the first cell
 * @fast: index of the second cell
 */
static void try_merge(int *line, size_t slow, size_t fast)
{
	if (line[slow] == 0 && line[fast] != 0)
	{
		line[slow] = line[fast];
		line[fast] = 0;
	}
	else if (line[slow] == line[fast])
	{
		line[slow] *= 2;
		line[fast] = 0;
	}
}

/**
 * slide_line - Merge a 2048 line
 * @line: Array of numbers, represent the 2048 line
 * @size: size of the array
 * @direction: direction of merging
 * Return: 1 if merging suceed, 0 otherwise
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t slow, fast, end;

	if (size <= 1)
	{
		return (1);
	}
	if (direction == SLIDE_LEFT)
	{
		slow = 0;
		fast = 1;
		end = size;
	}
	else if (direction == SLIDE_RIGHT)
	{
		slow = size - 1;
		fast = size - 2;
		end = -1;
	}
	else
	{
		return (0);
	}
	while (fast != end)
	{
		try_merge(line, slow, fast);
		if (line[fast] != 0)
		{
			slow += direction;
		}
		else
		{
			fast += direction;
		}

		if (fast == slow)
			fast += direction;
	}
	return (1);
}
