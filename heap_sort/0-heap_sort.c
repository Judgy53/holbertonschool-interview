#include <stdlib.h>
#include "sort.h"
#define left_child(i) (2 * i + 1)
#define right_child(i) (2 * i + 2)
#define parent(i) ((i - 1) / 2)

/**
 * swap - swap two elements and print the array
 * @array: pointer to the first element of the array to sort
 * @size: size of the array
 * @i: index of the first element to swap
 * @j: index of the second element to swap
 */
static void swap(int *array, size_t size, int i, int j)
{
	array[i] += array[j];
	array[j] = array[i] - array[j];
	array[i] -= array[j];
	print_array(array, size);
}

/**
 * siftDown - Repair the heap starting at index @root
 * @array: pointer to the first element of the array to sort
 * @size: size of the array
 * @root: index of the root
 * @end: upwards boundary to not go over
 */
static void siftDown(int *array, size_t size, int root, int end)
{
	int child;

	while (left_child(root) < end)
	{
		child = left_child(root);

		if (child + 1 < end && array[child] < array[child + 1])
		{
			child = child + 1;
		}

		if (array[root] < array[child])
		{
			swap(array, size, root, child);
			root = child;
		}
		else
		{
			return;
		}
	}
}

/**
 * heapify - rearrange the array into a binary max-heap
 * @array: pointer to the first element of the array to sort
 * @size: size of the array
 */
static void heapify(int *array, size_t size)
{
	int start = parent(size - 1) + 1;

	while (start > 0)
	{
		start -= 1;
		siftDown(array, size, start, size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: pointer to the first element of the array to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int end  = size;

	heapify(array, size);

	while (end > 1)
	{
		end -= 1;
		swap(array, size, end, 0);
		siftDown(array, size, 0, end);
	}
}
