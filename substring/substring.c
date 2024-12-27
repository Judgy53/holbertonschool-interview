#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * word_match - Checks if a given string matches a word.
 * @s: The string to compare.
 * @word: The word to match against.
 *
 * Return: 1 if the string matches the word, 0 otherwise.
 */
static int word_match(char const *s, char const *word)
{
	for (int i = 0; word[i] != '\0'; i++)
	{
		if (word[i] != s[i])
			return (0);
	}

	return (1);
}

/**
 * copy_words_except - Creates a copy of an array of words, excluding one word.
 * @words: The original array of words.
 * @nb_words: The number of words in the original array.
 * @except_index: The index of the word to exclude.
 *
 * Return: A new array of words excluding the word at except_index,
 *         or NULL if memory allocation fails.
 */
static char **copy_words_except(char **words, int nb_words, int except_index)
{
	char **copy = malloc(sizeof(char *) * (nb_words - 1));

	if (copy == NULL)
		return (NULL);

	for (int i = 0, j = 0; i < nb_words; i++)
	{
		if (i == except_index)
			continue;

		copy[j++] = strdup(words[i]);
	}

	return (copy);
}

/**
 * free_array - Frees a dynamically allocated array of strings.
 * @words: The array of strings to free.
 * @nb_words: The number of strings in the array.
 */
static void free_array(char **words, int nb_words)
{
	for (int i = 0; i < nb_words; i++)
		free(words[i]);

	free(words);
}

/**
 * search_concat - Searches for a concatenation of all words in a string.
 * @s: The string to search in.
 * @words: The array of words to concatenate.
 * @nb_words: The number of words in the array.
 *
 * Return: 1 if the concatenation is found, 0 otherwise.
 */
static int search_concat(char const *s, char **words, int nb_words)
{
	char **copy;
	int result;

	for (int i = 0; i < nb_words; i++)
	{
		if (word_match(s, words[i]))
		{
			if (nb_words == 1)
				return (1);

			copy = copy_words_except(words, nb_words, i);
			if (copy == NULL)
				return (0);

			result = search_concat(s + strlen(words[i]), copy, nb_words - 1);
			free_array(copy, nb_words - 1);

			if (result)
				return (1);
		}
	}

	return (0);
}

/**
 * find_substring - Finds all starting indices of substrings in a string
 *                  that are a concatenation of a given set of words.
 * @s: The string to search in.
 * @words: The array of words to concatenate.
 * @nb_words: The number of words in the array.
 * @n: Pointer to an integer where the number of results will be stored.
 *
 * Return: An array of starting indices of the substrings, or NULL if no
 *         such substrings are found or memory allocation fails.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *result;

	*n = 0;
	if (s == NULL || words == NULL || nb_words == 0)
		return (NULL);

	result = malloc(sizeof(int) * strlen(s));
	if (result == NULL)
		return (NULL);

	for (int s_index = 0; s[s_index] != '\0'; s_index++)
	{
		if (search_concat(s + s_index, (char **)words, nb_words))
		{
			result[*n] = s_index;
			(*n)++;
		}
	}

	return (result);
}
