#include "main.h"

/**
 * split_string_by_delimiters - function that splits a string into
 * words using delimiters
 * @input_str: the input string to be analyzed
 * @delim_str: the delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **split_string_by_delimiters(char *input_str, char *delim_str)
{
	int i, j, k, m, num_words = 0;
	char **word_array;

	if (input_str == NULL || input_str[0] == 0)
		return (NULL);
	if (!delim_str)
		delim_str = " ";
	for (i = 0; input_str[i] != '\0'; i++)
	{
		if (!is_delim(input_str[i], delim_str) && (is_delim(input_str[i + 1], delim_str) || !input_str[i + 1]))
		{
			num_words++;
		}
	}
	if (num_words == 0)
		return (NULL);
	word_array = malloc((1 + num_words) * sizeof(char *));
	if (!word_array)
		return (NULL);
	for (i = 0, j = 0; j < num_words; j++)
	{
		while (is_delim(input_str[i], delim_str))
			i++;
		k = 0;
		while (!is_delim(input_str[i + k], delim_str) && input_str[i + k])
			k++;
		word_array[j] = malloc((k + 1) * sizeof(char));
		if (!word_array[j])
		{
			for (k = 0; k < j; k++)
				free(word_array[k]);
			free(word_array);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			word_array[j][m] = input_str[i++];
		word_array[j][m] = 0;
	}
	word_array[j] = (NULL);
	return (word_array);
}

/**
 * split_string_by_single_delimiter - function that splits a string into
 * words using a single delimiter
 * @input_str: the input string to analyze
 * @delim: the delimiter character
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **split_string_by_single_delimiter(char *input_str, char delim)
{
	int i, j, k, m, num_words = 0;
	char **word_array;

	if (input_str == NULL || input_str[0] == 0)
		return (NULL);
	for (i = 0; input_str[i] != '\0'; i++)
	{
		if ((input_str[i] != delim && input_str[i + 1] == delim) ||
				(input_str[i] != delim && !input_str[i + 1]) || input_str[i + 1] == delim)
		{
			num_words++;
		}
	}
	if (num_words == 0)
		return (NULL);
	word_array = malloc((1 + num_words) * sizeof(char *));
	if (!word_array)
		return (NULL);
	for (i = 0, j = 0; j < num_words; j++)
	{
		while (input_str[i] == delim && input_str[i] != delim)
			i++;
		k = 0;
		while (input_str[i + k] != delim && input_str[i + k] &&
				input_str[i + k] != delim)
			k++;
		word_array[j] = malloc((k + 1) * sizeof(char));
		if (!word_array[j])
		{
			for (k = 0; k < j; k++)
				free(word_array[k]);
			free(word_array);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			word_array[j][m] = input_str[i++];
		word_array[j][m] = 0;
	}
	word_array[j] = (NULL);
	return (word_array);
}
