#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order using Radix sort
 * @array: pointer to the array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int increase_radix = 1;
	int radix = 1;

	while (increase_radix)
	{
		increase_radix = sort_one_digit(array, size, radix);
		radix *= 10;
	}
}


/**
 * sort_one_digit - sort array based on one digit
 * @array: pointer to the array to sort
 * @size: size of the array
 * @radix: radix of the digit used to sort the array
 *
 * Return: Amount of entries greater than current radix
 */
int sort_one_digit(int *array, size_t size, int radix)
{
	int increase_radix = 0;
	int buckets[10] = {0};
	int sorted[size];

	/* count occurences of digits at radix */
	for (size_t i = 0; i < size; i++)
	{
		int digit = (array[i] / radix) % 10;

		buckets[digit]++;
		increase_radix += array[i] >= radix ? 1 : 0;
	}

	/* don't bother continuing if all numbers are smaller than radix*/
	if (!increase_radix)
		return (0);

	/* convert occurences to array positions */
	for (size_t i = 1; i < 10; i++)
		buckets[i] += buckets[i - 1];

	/* build the sorted array */
	for (size_t i = size; i >= 1; i--)
	{
		int digit = (array[i - 1] / radix) % 10;

		sorted[buckets[digit] - 1] = array[i - 1];
		buckets[digit]--;
	}

	/* copy sorted array to initial array */
	for (size_t i = 0; i < size; i++)
		array[i] = sorted[i];

	print_array(array, size);

	return (increase_radix);
}
