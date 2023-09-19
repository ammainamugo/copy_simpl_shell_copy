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
