#include "main.h"

/**
 * split_string_by_delimiters - function that splits a string into
 * words using delimiters
 * @input_str: the input string to be analyzed
 * @delimiter_str: the delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **split_string_by_delimiters(char *input_str, char *delimiter_str)
{
	int i, j, k, m, num_words = 0;
	char **word_array;

	if (input_str == NULL || input_str[0] == 0)
		return (NULL);
	if (!delimiter_str)
		delimiter_str = " ";
	for (i = 0; input_str[i] != '\0'; i++)
	{
		if (!is_delimiter(input_str[i], delimiter_str) &&
				(is_delimiter(input_str[i + 1], delimiter_str) || !input_str[i + 1]))
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
		while (is_delimiter(input_str[i], delimiter_str))
			i++;
		k = 0;
		while (!is_delimiter(input_str[i + k], delimiter_str) && input_str[i + k])
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
 * @delimiter: the delimiter character
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **split_string_by_single_delimiter(char *input_str, char delimiter)
{
	int i, j, k, m, num_words = 0;
	char **word_array;

	if (input_str == NULL || input_str[0] == 0)
		return (NULL);
	for (i = 0; input_str[i] != '\0'; i++)
	{
		if ((input_str[i] != delimiter && input_str[i + 1] == delimiter) ||
				(input_str[i] != delimiter && !input_str[i + 1]) ||
				input_str[i + 1] == delimiter)
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
		while (input_str[i] == delimiter && input_str[i] != delimiter)
			i++;
		k = 0;
		while (input_str[i + k] != delimiter && input_str[i + k] &&
				input_str[i + k] != delimiter)
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
