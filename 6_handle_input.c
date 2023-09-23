#include "main.h"

/**
 * p_string - prints string
 * @s: string to be printed
 * Return: Nothing
 */
void p_string(char *s)
{
	int a = 0;

	if (!s)
		return;
	while (s[a] != '\0')
	{
		pr_error(s[a]);
		a++;
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
	int a = 0;

	if (!s)
		return (0);
	while (*s)
	{
		a += wri_fd(*s++, fd);
	}
	return (a);
}

/**
 * handle_d - prints decimal (integer) number
 * @in: input given
 * @fd: file descriptor to write to
 * Return: number of characters printed
 */
int handle_d(int in, int fd)
{
	int (*_print_out)(char) = print_out;
	int count, a = 0;
	unsigned int _abs_, n;

	if (fd == STDERR_FILENO)
		_print_out = pr_error;

	if (in < 0)
	{
		_abs_ = -in;
		_print_out('-');
		count++;
	}
	else
		_abs_ = in;
	n = _abs_;
	for (a = 1000000000; a > 1; a /= 10)
	{
		if (_abs_ / a)
		{
			_print_out('0' + num / a);
			count++;
		}
		num %= a;
	}
	_print_out('0' + n);
	count++;

	return (count);
}
