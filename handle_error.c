#include "main.h"

/**
 * pr_error - writes character c to stderr
 * @c: character to print
 * Return: On success 1.
 * On error: -1 is returned, and error no. is set appropriately.
 */
int pr_error(char c)
{
	static int i;
	static char buff[WR_BUF_SIZE];

	if (c == BUFF_FLUSH || i >= WR_BUF_SIZE)
	{
		write(2, buff, i);
		i = 0;
	}
	if (c != BUFF_FLUSH)
		buff[i++] = c;
	return (1);
}

/**
 * wri_fd - writes character to given fd
 * @c: character to print
 * @fd: filedescriptor to write to
 * Return: On success 1.
 * On error: -1 is returned, and error no. is set appropriately.
 */
int wri_fd(char c, int fd)
{
	static int i;
	static char buff[WR_BUF_SIZE];

	if (c == BUFF_FLUSH || i >= WR_BUF_SIZE)
	{
		write(fd, buff, i);
		i = 0;
	}
	if (c != BUFF_FLUSH)
		buff[i++] = c;
	return (1);
}

/**
 * atoi_er - converts string to an integer
 * @st: string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 * -1 on error
 */
int atoi_er(char *st)
{
	int i = 0;
	unsigned long int r = 0;

	if (*st == '+')
		st++;
	for (i = 0;  st[i] != '\0'; i++)
	{
		if (st[i] >= '0' && st[i] <= '9')
		{
			r *= 10;
			r += (st[i] - '0');
			if (r > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (r);
}

/**
 * perr_msg - prints error message
 * @inf: the parameter & return info struct
 * @est: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 * -1 on error
 */
void perr_msg(info_type *inf, char *est)
{
	p_string(inf->fn);
	p_string(": ");
	handle_d(inf->line_count, STDERR_FILENO);
	p_string(": ");
	p_string(inf->argv[0]);
	p_string(": ");
	p_string(est);
}
