#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "holberton.h"

/**
 * is_digits - Determine if a str only has digits in it
 * @str: pointer to the first character of the string
 *
 * Return: 1 if it only has digits, 0 otherwise
 */
int is_digits(char *str)
{
	for (int index = 0; str[index]; index++)
	{
		if (str[index] < '0' || str[index] > '9')
		{
			return (0);
		}
	}
	return (1);
}

/**
 * are_arguments_valid - Tests if arguments are valid
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 1 if valid, 0 otherwise
 */
int are_arguments_valid(int argc, char **argv)
{
	if (argc != 3)
	{
		return (0);
	}
	if (!is_digits(argv[1]) || !is_digits(argv[2]))
	{
		return (0);
	}
	return (1);
}

/**
 * print_error_and_exit - print error message and exit with code 98
 */
void print_error_and_exit(void)
{
	char *str = "Error\n";

	for (int index = 0; str[index]; index++)
		_putchar(str[index]);

	exit(98);
}

/**
 * print_result - print the result array
 * @result: result array
 * @result_len: length of the array
 */
void print_result(char *result, int result_len)
{
	int skip = 1;

	for (int result_index = 0; result_index < result_len; result_index++)
	{
		if (result[result_index] == 0 && skip)
			continue;
		skip = 0;
		_putchar(result[result_index] + '0');
	}
	if (skip)
		_putchar('0');
	_putchar('\n');
}

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, error code 98 on failure
 */
int main(int argc, char *argv[])
{
	char *left, *right, *result;
	int result_len, remainder;

	if (!are_arguments_valid(argc, argv))
		print_error_and_exit();

	left = argv[1];
	right = argv[2];

	result_len = strlen(left) + strlen(right);
	result = malloc(sizeof(char) * result_len);
	if (!result)
		print_error_and_exit();

	for (int result_index = 0; result_index < result_len; result_index++)
		result[result_index] = 0;

	for (int left_index = strlen(left) - 1; left_index >= 0; left_index--)
	{
		char left_digit = left[left_index] - '0';

		remainder = 0;
		for (int right_index = strlen(right) - 1; right_index >= 0; right_index--)
		{
			int result_index = left_index + right_index + 1;
			char right_digit = right[right_index] - '0';
			char mult = left_digit * right_digit + remainder;
			char add = result[result_index] + (mult % 10);

			remainder = (mult / 10) + (add / 10);
			result[result_index] = add % 10;
		}
		result[left_index] = remainder;
	}
	print_result(result, result_len);
	free(result);

	return (0);
}
