#include "regex.h"
#include <stdio.h>


/**
 * regex_match - Checks whether a given pattern matches a given string.
 * @str: pointer to the string to scan
 * @pattern: pointer to the regular expression string
 * Return: 1 if the pattern matches, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return (1);

	if (*(pattern + 1) == '*')
	{
		int match = regex_match(str, pattern + 2);

		if (*str != '\0')
			match = match || regex_match(str + 1, pattern);

		return (match);
	}

	if (*str == *pattern || *pattern == '.')
		return (regex_match(str + 1, pattern + 1));

	return (0);
}
