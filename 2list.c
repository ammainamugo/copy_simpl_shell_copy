#include "main.h"

/**
 * lenlist - determines length of linked list
 * @h: pointer to first node
 * Return: size of list
 */
type_size lenlist(const type_list *h)
{
	type_size a = 0;

	while (h)
	{
		h = h->next;
		a++;
	}
	return (a);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @n: pointer to list head
 * @pre: string to match
 * @ch: the next character after prefix to match
 * Return: node or null
 */
type_list *node_starts_with(type_list *n, char *pre, char ch)
{
	char *p = NULL;

	while (n)
	{
		p = starts_with(n->str, pre);
		if (p && ((ch == -1) || (*p == ch)))
			return (n);
		n = n->next;
	}
	return (NULL);
}

/**
 * pr_list - prints all elements of a linked list
 * @h: pointer to first node
 * Return: size of list
 */
type_size pr_list(const type_list *h)
{
	type_size i = 0;

	while (h)
	{
		p_string(convert_number(h->num, 10, 0));
		print_out(':');
		print_out(' ');
		p_strings(h->str ? h->str : "(nil)");
		p_string("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_index - gets index of a node
 * @h: pointer to list head
 * @n: pointer to the node
 * Return: index of node or -1
 */
ttype_size node_index(type_list *h, type_list *n)
{
	type_size a = 0;

	while (h)
	{
		if (h == n)
			return (a);
		h = h->next;
		a++;
	}
	return (-1);
}

/**
 * list_str - returns array of strings of list
 * @h: pointer to first node
 * Return: array of strings
 */
char **list_str(type_list *h)
{
	type_list *node = h;
	type_size a = lenlist(h), b;
	char **st;
	char *s;

	if (!h || !i)
		return (NULL);
	st = malloc(sizeof(char *) * (a + 1));
	if (!st)
		return (NULL);
	for (a = 0; node; node = node->next, a++)
	{
		s = malloc(stlen(node->s) + 1);
		if (!s)
		{
			for (b = 0; b < a; b++)
				free(strs[b]);
			free(st);
			return (NULL);
		}

		s = stcopy(s, node->s);
		st[a] = s;
	}
	st[i] = NULL;
	return (st);
}
