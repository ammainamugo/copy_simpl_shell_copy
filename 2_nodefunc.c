#include "main.h"

/**
 * node_add - adds node to start of list
 * @h: address of pointer to head node
 * @s: str field of node
 * @n: node index used by history
 * Return: size of list
 */
type_list *node_add(type_list **h, const char *s, int n)
{
	type_list *h_new;

	if (!h)
		return (NULL);
	type_list h_new = malloc(sizeof(type_list));
	if (!h_new)
		return (NULL);
	set_mem((void *)h_new, 0, sizeof(type_list));
	h_new->n = n;
	if (s)
	{
		h_new->s = dup_s(s);
		if (!h_new->s)
		{
			free(h_new);
			return (NULL);
		}
	}
	h_new->next = *h;
	*h = h_new;
	return (h_new);
}

/**
 * nodeadd_end - adds a node to the end of the list
 * @h: address of pointer to head node
 * @s: str field of node
 * @n: node index used by history
 * Return: size of list
 */
type_list *nodeadd_end(type_list **h, const char *s, int n)
{
	type_list *n_node, *node;

	if (!h)
		return (NULL);

	node = *h;
	n_node = malloc(sizeof(type_list));
	if (!n_node)
		return (NULL);
	set_mem((void *)n_node, 0, sizeof(type_list));
	n_node->n = n;
	if (s)
	{
		n_node->s = dup_s(s);
		if (!n_node->s)
		{
			free(n_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = n_node;
	}
	else
		*h = n_node;
	return (n_node);
}

/**
 * node_delete - deletes node at given index
 * @h: address of pointer to first node
 * @ind: index of node to delete
 * Return: 1 on success, 0 on failure
 */
int node_delete(type_list **h, unsigned int ind)
{
	type_list *node, *pnode;
	unsigned int a = 0;

	if (!h || !*h)
		return (0);

	if (!ind)
	{
		node = *h;
		*h = (*h)->next;
		free(node->s);
		free(node);
		return (1);
	}
	node = *h;
	while (node)
	{
		if (a == ind)
		{
			pnode->next = node->next;
			free(node->s);
			free(node);
			return (1);
		}
		a++;
		pnode = node;
		node = node->next;
	}
	return (0);
}

/**
 * start_node - returns node whose string starts with prefix
 * @n: pointer to list head
 * @pre: string to match
 * @ch: the next character after prefix to match
 * Return: node or null
 */
type_list *start_node(type_list *n, char *pre, char ch)
{
	char *a = NULL;

	while (n)
	{
		a = chk_start(n->s, pre);
		if (a && ((ch == -1) || (*a == ch)))
			return (n);
		n = n->next;
	}
	return (NULL);
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
