#include "main.h"

/**
 * node_add - adds node to start of list
 * @h: address of pointer to head node
 * @s: str field of node
 * @num: node index used by history
 * Return: size of list
 */
type_list *node_add(type_list **h, const char *s, int num)
{
	type_list *h_new;

	if (!h)
		return (NULL);
	h_new = malloc(sizeof(type_list));
	if (!h_new)
		return (NULL);
	_memset((void *)h_new, 0, sizeof(type_list));
	h_new->num = num;
	if (s)
	{
		h_new->s = _strdup(s);
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
 * @num: node index used by history
 * Return: size of list
 */
type_list *nodeadd_end(type_list **h, const char *s, int num)
{
	type_list *n_node, *node;

	if (!h)
		return (NULL);

	node = *h;
	n_node = malloc(sizeof(type_list));
	if (!n_node)
		return (NULL);
	_memset((void *)n_node, 0, sizeof(type_list));
	n_node->num = num;
	if (s)
	{
		n_node->s = _strdup(s);
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
	type_list *node, *prev_node;
	unsigned int i = 0;

	if (!h || !*h)
		return (0);

	if (!ind)
	{
		node = *h;
		*h = (*h)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *h;
	while (node)
	{
		if (i == ind)
		{
			p_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		p_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * p_list_str - prints only the str element of a type_list linked list
 * @h: pointer to first node
 * Return: size of list
 */
type_size p_list_str(const type_list *h)
{
	type_size a = 0;

	while (h)
	{
		p_string(h->str ? h->str : "(nil)");
		p_string("\n");
		h = h->next;
		a++;
	}
	return (a);
}

/**
 * listfree - frees all nodes of a list
 * @head_p: address of pointer to head node
 * Return: void
 */
void listfree(type_list **head_p)
{
	type_list *node, *n_node, *head;

	if (!head_p || !*head_p)
		return;
	head = *head_p;
	node = head;
	while (node)
	{
		n_node = node->next;
		free(node->str);
		free(node);
		node = n_node;
	}
	*head_p = NULL;
}
