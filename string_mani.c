#include "main.h"

/**
 **stcat - concatenates two strings
 *@dest: given string
 *@src: second string
 *@byte: the amount of bytes to be maximally used
 *Return: concatenated string
 */
char *stcat(char *dest, char *src, int byte)
{
	int a, b;
	char *str = dest;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < byte)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	if (b < byte)
		dest[a] = '\0';
	return (str);
}

/**
 **stcpy - copies string
 *@dest: destination string
 *@src: source string
 *@total: amount of characters to be copied
 *Return: copied string
 */
char *stcpy(char *dest, char *src, int total)
{
	int a, b;
	char *str = dest;

	a = 0;
	while (src[a] != '\0' && a < total - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < total)
	{
		b = a;
		while (b < total)
		{
			dest[b] = '\0';
			b++;
		}
	}
	return (str);
}

/**
 **loc_chr - locates a character in a string
 *@str: string to be parsed
 *@ch: character to look for
 *Return: a pointer to the memory area str
 */
char *loc_chr(char *str, char ch)
{
	do {
		if (*str == ch)
			return (str);
	}
	while (*str++ != '\0');
	return (NULL);
}
