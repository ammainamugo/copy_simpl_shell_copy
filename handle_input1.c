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

/**
 * handle_d - prints decimal (integer) number
 * @in: input given
 * @fd: file descriptor to write to
 * Return: number of characters printed
 */
int handle_d(int in, int fd)
{
	int (*_print_out)(char) = print_out;
	int count, i = 0;
	unsigned int _abs_, num;

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
	num = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			_print_out('0' + num / i);
			count++;
		}
		num %= i;
	}
	_print_out('0' + num);
	count++;

	return (count);
}
