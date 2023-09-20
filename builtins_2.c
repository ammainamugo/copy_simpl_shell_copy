#include "main.h"

/**
 * display_command_history - function to displays the
 * command history list with line numbers
 * @info: Structure containing potential arguments.
 * Used to maintain constant function prototype.
 * Return: Success always 0
 */

int display_command_history(info_t *info)
{
	print_history_list(info->history);
	return (0);
}

/**
 * remove_alias - function that removes an alias from the alias list
 * @info: Parameter struct
 * @alias_string: The string alias to be removed
 * Return: 0 on success, 1 on error
 */

int remove_alias(info_t *info, char *alias_string)
{
char *equal_sign_position, saved_char;
int result;

equal_sign_position = strchr(alias_string, '=');
if (!equal_sign_position)
	return (1);
saved_char = *equal_sign_position;
*equal_sign_position = '\0';
result = delete_alias_by_name(&(info->alias), alias_string);
*equal_sign_position = saved_char;
return (result);
}

/**
 * add_alias - function that sets an alias to a string
 * @info: Parameter struct
 * @alias_string: The string alias to be set
 * Return: 0 on success, 1 on error
 */

int add_alias(info_t *info, char *alias_string)
{
	char *equal_sign_position;

	equal_sign_position = strchr(alias_string, '=');
	if (!equal_sign_position)
		return (1);
	*equal_sign_position = '\0';
	remove_alias(info, alias_string);
	return (add_alias_to_list(&(info->alias), alias_string) == NULL);
}

/**
 * print_single_alias - function that prints a single alias string
 * @alias_node: The alias node to print
 * Return: 0 on success, 1 on error
 */

int print_single_alias(alias_t *alias_node)
{
	char *equal_sign_position;

	if (alias_node)
	{
		equal_sign_position = strchr(alias_node->alias_string, '=');
		if (equal_sign_position)
		{
			*equal_sign_position = '\0';
			printf("%s='%s'\n", alias_node->alias_string, equal_sign_position + 1);
			*equal_sign_position = '=';
			return (0);
		}
	}
	return (1);
}

/**
 * manage_aliases - function that manages aliases, similar
 * to the alias built-in command
 * @info: Structure containing potential arguments
 * Return: Success always 0
 */

int manage_aliases(info_t *info)
{
	int i;
	char *equal_sign_position;
	alias_t *alias_node;

	if (info->argc == 1)
	{
		alias_node = info->alias;
		while (alias_node)
		{
			print_single_alias(alias_node);
			alias_node = alias_node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		equal_sign_position = strchr(info->argv[i], '=');
		if (equal_sign_position)
			add_alias(info, info->argv[i]);
		else
			print_single_alias(find_alias_by_name(info->alias, info->argv[i]));
	}
	return (0);
}
