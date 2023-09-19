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
