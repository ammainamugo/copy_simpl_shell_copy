#include "main.h"

/**
 * write_character - function that writes a character to the standard output
 * @ch: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and error no is set appropriately
 */

int write_character(char ch)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
	write(1, buf, i);
	i = 0;
}
if (ch != BUF_FLUSH)
	buf[i++] = ch;
	return (1);
	}
