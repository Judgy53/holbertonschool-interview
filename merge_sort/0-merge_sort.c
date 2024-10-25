#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

int *copy_array(int *array, size_t size);
void split_merge(int *array, size_t start, size_t end, int *temp);
void merge(int *array, size_t start, size_t middle, size_t end, int *temp);

/**
 * merge_sort - sorts an array of int using the merge sort algorithm
 *
 * @array: pointer to the array to sort
 * @size: size of @array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size <= 1)
	{
		return;
	}

	temp = copy_array(array, size);
	if (!temp)
	{
		return;
	}

	split_merge(array, 0, size, temp);
	free(temp);
}

/**
 * split_merge - Split the array in 2, sorts both parts and merge them
 * @array: pointer to the array to sort
 * @start: start index (inclusive) of the slice to process
 * @end: end index (exclusive) of the slice to process
 * @temp: pointer to the work array
 */
void split_merge(int *array, size_t start, size_t end, int *temp)
{
	size_t middle = (end + start) / 2;

	if (end - start <= 1)
	{
		return;
	}

	split_merge(array, start, middle, temp);
	split_merge(array, middle, end, temp);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, middle - start);
	printf("[right]: ");
	print_array(array + middle, end - middle);

	merge(array, start, middle, end, temp);

	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * merge - Sort and Merge 2 half of an array
 * @array: pointer to the array to sort
 * @start: start index (inclusive) of the slice to process
 * @middle: middle index (exclusive), indicates where left slice end
 * @end: end index (exclusive) of the slice to process
 * @temp: work array
 */
void merge(int *array, size_t start, size_t middle, size_t end, int *temp)
{
	size_t i = start, j = middle, k = 0;

	while (i < middle && j < end)
	{
		if (array[i] < array[j])
		{
			temp[k++] = array[i++];
		}
		else
		{
			temp[k++] = array[j++];
		}
	}

	while (i < middle)
	{
		temp[k++] = array[i++];
	}

	while (j < end)
	{
		temp[k++] = array[j++];
	}

	i = start;
	k = 0;
	while (i < end)
	{
		array[i++] = temp[k++];
	}
}

/**
 * copy_array - duplicates an entire array of int
 *
 * @array: pointer to the array to duplicate
 * @size: Number of elements in @orig_array
 *
 * Return: pointer to the duplicated array, or (NULL) if it failed
 */
int *copy_array(int *array, size_t size)
{
	int *copy = malloc(sizeof(int) * size);

	if (!copy)
	{
		return (NULL);
	}

	for (size_t i = 0; i < size; i++)
	{
		copy[i] = array[i];
	}

	return (copy);
}
