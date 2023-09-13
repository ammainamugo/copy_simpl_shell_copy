#include "main.h"

/**
 * interactive - checks if the shell is running in an interactive mode
 * @info: struct address
 *
 * Return: 1 if it is an interactive mode, 0 if not
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimiter - checks if given character is a delimeter
 * @ch: the char to check if is a delimiter
 * @delim: delimeter string
 * Return: 1 if character is delimiter, 0 if otherwise
 */

int is_delimiter(char ch, char *delim)
{
	while (*delim)
		if (*delim++ == ch)
			return (1);
	return (0);
}

/**
 * _isalphabetic - function that checks whether a character is alphabetic
 * @ch: character to to check
 * Return: 1 if character is alphabetic, 0 otherwise
 */

int _isalphabetic(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - function parses a string to convert into an integer
 * @s: the string to convert
 *
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
