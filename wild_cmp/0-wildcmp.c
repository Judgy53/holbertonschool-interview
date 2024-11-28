#include "holberton.h"

/**
 * wildcmp - Compares two strings with wildcard "*".
 * @s1: Pointer to the first string
 * @s2: Pointer to the second string.
 *
 * Return: 1 if the strings are identical, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0') /* Both strings have no char left */
		return (1);

	if (*s1 == '\0' && *s2 != '*') /* Only s2 has char left */
		return (0);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	if (*s2 != '*')
		return (0);

	if (*s1 == '\0')
		return (wildcmp(s1, s2 + 1));

	return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
}
