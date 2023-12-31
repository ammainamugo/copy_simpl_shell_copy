#include "main.h"

/**
 * display_environment - function that prints the
 * current environment variables
 * @info: Structure containing potential arguments
 * Return: Success always 0
 */

int display_environment(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * get_environment_variable - funcction that gets the
 * value of an environment variable
 * @info: Structure containing potential arguments
 * @name: The name of the environment variable
 * Return: The value of the environment variable or NULL if not found
 *
 */

char *get_environment_variable(info_t *info, const char *name)
{
list_t *node = info->env;
char *p;

while (node)
{
	p = starts_with(node->str, name);
	if (p && *p)
		return (p);
	node = node->next;
}
return (NULL);
}

/**
 * set_environment_variable - function that initializes a new
 * environment variable or modifies an existing one
 * @info: Structure containing potential arguments
 * Return: 0 success, 1 failure
 */

int set_environment_variable(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments.\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * unset_environment_variable - function that removes an environment variable
 * @info: Structure containing potential arguments
 * Return: 0 success, 1 failure
 */

int unset_environment_variable(info_t *info)
{
int i;

if (info->argc == 1)
{
_eputs("Too few arguments.\n");
return (1);
}
for (i = 1; i < info->argc; i++)
_unsetenv(info, info->argv[i]);
return (0);
}

/**
 * populate_environment_list - function that populates the
 * environment linked list from the system environment
 * @info: Structure containing potential arguments
 * Return: Success always 0
 */

int populate_environment_list(info_t *info)
{
list_t *node = NULL;
size_t i;

for (i = 0; environ[i]; i++)
add_node_end(&node, environ[i], 0);
info->env = node;
return (0);
}
