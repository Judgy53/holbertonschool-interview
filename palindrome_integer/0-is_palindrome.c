#include "palindrome.h"

/**
 * is_palindrome - Check if an unsigned integer is a palindrome
 * @n: the number to be checked
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0;
	unsigned long remainder = n;

	while (remainder != 0)
	{
		reversed *= 10;
		reversed += remainder % 10;
		remainder /= 10;
	}

	return (n == reversed);
}
