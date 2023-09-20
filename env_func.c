#include "main.h"

/**
 * fin_env - returns string array copy of our environ
 * @inf: structure containing potential arguments used to maintain
 * constant function prototype
 * Return: Always 0
 */
char **fin_env(type_info *inf)
{
	if (!inf->env || inf->ch_env)
	{
		inf->env = list_str(inf->env);
		inf->ch_env = 0;
	}

	return (inf->env);
}

/**
 * reset_env - Removes an environment variable
 * @inf: structure containing potential arguments used to maintain
 * constant function prototype.
 * @v: the string env var property
 * Return: 1 on delete, 0 otherwise
 */
int reset_env(type_info *inf, char *v)
{
	type_list *node = inf->env;
	type_size a = 0;
	char *b;

	if (!node || !v)
		return (0);

	while (node)
	{
		b = chk_start(node->str, v);
		if (b && *b == '=')
		{
			inf->ch_env = delete_node_at_index(&(inf->env), a);
			a = 0;
			node = inf->env;
			continue;
		}
		node = node->next;
		a++;
	}
	return (inf->ech_env);
}

/**
 * set_env - Initialize new environment variable or modify existing one
 * @inf: structure containing potential arguments used to maintain
 * constant function prototype.
 * @v: string env var property
 * @value: the string env var value
 * Return: Success (Always 0)
 */
int set_env(type_info *inf, char *v, char *value)
{
	char *buff = NULL;
	type_list *node;
	char *b;

	if (!v || !value)
		return (0);

	buff = malloc(stlen(var) + stlen(value) + 2);
	if (!buff)
		return (1);
	stcopy(buf, var);
	stccat(buff, "=");
	stccat(buff, value);
	node = inf->env;
	while (node)
	{
		b = chk_start(node->str, v);
		if (b && *b == '=')
		{
			free(node->str);
			node->str = buff;
			inf->ch_env = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(inf->env), buff, 0);
	free(buff);
	inf->ch_env = 1;
	return (0);
}
