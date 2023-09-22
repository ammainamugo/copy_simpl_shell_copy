#include "main.h"

/**
 * p_list_str - prints only the str element of a type_list linked list
 * @p: pointer to first node
 * Return: size of list
 */
type_size p_list_str(const type_list *p)
{
	type_size a = 0;

	while (p)
	{
		p_string(h->str ? h->str : "(nil)");
		p_string("\n");
		p = p->next;
		a++;
	}
	return (a);
}


/**
 * lenlist - determines length of linked list
 * @p: pointer to first node
 * Return: size of list
 */
type_size lenlist(const type_list *p)
{
	type_size a = 0;

	while (p)
	{
		p = p->next;
		a++;
	}
	return (a);
}

/**
 * pr_list - prints all elements of a linked list
 * @p: pointer to first node
 * Return: size of list
 */
type_size pr_list(const type_list *p)
{
	type_size a = 0;

	while (p)
	{
		p_string(num_convert(p->num, 10, 0));
		print_out(':');
		print_out(' ');
		p_strings(p->str ? p->str : "(nil)");
		p_string("\n");
		p = p->next;
		a++;
	}
	return (a);
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

	if (!h || !a)
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
				free(st[b]);
			free(st);
			return (NULL);
		}

		s = stcopy(s, node->s);
		st[a] = s;
	}
	st[a] = NULL;
	return (st);
}

/**
 * listfree - frees all nodes of a list
 * @ph: address of pointer to head node
 * Return: void
 */
void listfree(type_list **ph)
{
	type_list *node, *n_node, *h;

	if (!ph || !*ph)
		return;
	h = *ph;
	node = h;
	while (node)
	{
		n_node = node->next;
		free(node->s);
		free(node);
		node = n_node;
	}
	*ph = NULL;
}
