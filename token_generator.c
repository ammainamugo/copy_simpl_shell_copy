#include "main.h"

/**
 * **split_string_by_delimiters - function that splits a string into words
 * Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **split_string_by_delimiters(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
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
