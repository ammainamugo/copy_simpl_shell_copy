#include "main.h"

/**
 * p_string - prints string
 * @s: string to be printed
 * Return: Nothing
 */
void p_string(char *s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		pr_error(s[i]);
		i++;
	}
}

/**
 * pfd_string - prints input string to fd
 * @s: string to be printed
 * @fd: filedescriptor to write to
 * Return: total number of chars
 */
int pfd_string(char *s, int fd)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s)
	{
		i += wri_fd(*s++, fd);
	}
	return (i);
}
