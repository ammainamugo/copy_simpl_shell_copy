#include "main.h"

/**
 * is_chain_delimiter - function that checks if the current
 * character in the buffer is a chain delimiter
 * @info: pointer to the parameter structure
 * @buffer: character buffer
 * @position: address of the current position in the buffer
 *
 * Return: 1 if it's a chain delimiter, 0 otherwise
 */

int is_chain_delimiter(info_t *info, char *buffer, size_t *position)
{
	size_t current_pos = *position;

	if (buffer[current_pos] == '|' && buffer[current_pos + 1] == '|')
	{
		buffer[current_pos] = 0;
		current_pos++;
		info->command_buffer_type = CMD_OR;
	}
	else if (buffer[current_pos] == '&' && buffer[current_pos + 1] == '&')
	{
		buffer[current_pos] = 0;
		current_pos++;
		info->command_buffer_type = CMD_AND;
	}
	else if (buffer[current_pos] == ';') /* found the end of this command */
	{
		buffer[current_pos] = 0; /* replace semicolon with null */
		info->command_buffer_type = CMD_CHAIN;
	}
	else
	{
		return (0);
	}

	*position = current_pos;
	return (1);
}

/**
 * check_chain_continue -function that checks if chaining
 * should continue based on the last status
 * @info: pointer to the parameter structure
 * @buffer: character buffer
 * @position: address of the current position in the buffer
 * @start_position: starting position in the buffer
 * @length: length of the buffer
 *
 * Return: Void
 */

void check_chain_continue(info_t *info, char *buffer, size_t *position, size_t start_position, size_t length)
{
	size_t current_pos = *position;

	if (info->command_buffer_type == CMD_AND)
	{
		if (info->status)
		{
			buffer[start_position] = 0;
			current_pos = length;
		}
	}
	if (info->command_buffer_type == CMD_OR)
	{
		if (!info->status)
		{
			buffer[start_position] = 0;
			current_pos = length;
		}
	}

	*position = current_pos;
}

/**
 * replace_alias - function that replaces aliases in the tokenized string
 * @info: pointer to the parameter structure
 *
 * Return: 1 if replaced, 0 otherwise
 */

int replace_aliases(info_t *info)
{
	int i;
	list_t *node;
	char *equal_sign_ptr;

	for (i = 0; i < 10; i++)
	{
		node = find_alias_node(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		equal_sign_ptr = _strchr(node->str, '=');
		if (!equal_sign_ptr)
			return (0);
		equal_sign_ptr = _strdup(equal_sign_ptr + 1);
		if (!equal_sign_ptr)
			return (0);
		info->argv[0] = equal_sign_ptr;
	}
	return (1);
}

/**
 * replace_variables - function that replaces
 * variables in the tokenized string
 * @info: pointer to the parameter structure
 *
 * Return: 1 if replaced, 0 otherwise
 */

int replace_variables(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = find_variable_node(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));
	}
	return (0);
}

/**
 * replace_string - function that replaces a string
 * @old_str: pointer to the address of the old string
 * @new_str: pointer to the new string
 *
 * Return: 1 if replaced, 0 otherwise
 */

int replace_string(char **old_str, char *new_str)
{
	free(*old_str);
	*old_str = new_str;
	return (1);
}
