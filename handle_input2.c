#include "main.h"

/**
 * num_convert - convert an integer to a string
 * @nu: number
 * @ba: base
 * @fl: argument flags
 * Return: string
 */
char *num_convert(long int nu, int ba, int fl)
{
	static char *ar;
	static char buf[50];
	char si = 0;
	char *p;
	unsigned long n = nu;

	if (!(fl & CHANGE_UNSIGNED) && nu < 0)
	{
		n = -nu;
		si = '-';

	}
	ar = fl & CHANGE_LCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buf[49];
	*p = '\0';

	do	{
		*--p = ar[n % ba];
		n /= ba;
	} while (n != 0);

	if (si)
		*--p = si;
	return (p);
}

/**
 * comment_rm - function replaces first instance of '#' with '\0'
 * @buff: address of the string to modify
 * Return: Always 0;
 */
void comment_rm(char *buff)
{
	int a;

	for (a = 0; buff[i] != '\0'; a++)
		if ((!a || buff[a - 1] == ' ') && buff[i] == '#')
		{
			buff[a] = '\0';
			break;
		}
}
