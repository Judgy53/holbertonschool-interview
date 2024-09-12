#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * print_array - print a slice of an array
 * @array: array to print
 * @start: index of the start of the slice
 * @end: index of the end of the slice
 */
static void print_array(int *array, int start, int end)
{
	printf("Searching in array: ");
	while (start < end)
	{
		printf("%i, ", array[start++]);
	}

	printf("%i\n", array[start]);
}

/**
 * recursive_binary - binary search a value in a slice of an array
 * @array: array to search
 * @start: index of the start of the slice
 * @end: index of the end of the slice
 * @value: value to find
 *
 * Return: index
 */
static int recursive_binary(int *array, int start, int end, int value)
{
	int mid = (end - start) / 2 + start;

	print_array(array, start, end);

	if (start == end)
		return (-1);

	if (array[mid] == value && array[mid - 1] != value)
		return (mid);

	if (array[mid] >= value)
		return (recursive_binary(array, start, mid, value));

	if (array[mid] <= value)
		return (recursive_binary(array, mid + 1, end, value));

	return (-1);
}

/**
 * advanced_binary - search for a value in a sorted array of integers.
 * @array: array to search in
 * @size: length of the array
 * @value: value to find
 *
 * Return: index of the value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (recursive_binary(array, 0, size - 1, value));
}
