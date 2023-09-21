#include "main.h"

/**
 * string_copy - function that copies a source string to a
 * destination string
 * @destination: the destination string
 * @source: the source string
 * Return: pointer to the destination string
 */

char *string_copy(char *destination, char *source)
{
	int index = 0;

	if (destination == source || source == NULL)
		return (destination);
	while (source[index])
	{
		destination[index] = source[index];
		index++;
	}
	destination[index] = '\0';
	return (destination);
}

/**
 * string_duplicate - function that duplicates a string
 * @str_to_duplicate: the string to duplicate
 * Return: pointer to the duplicated string
 */

char *string_duplicate(const char *str_to_duplicate)
{
	int length = 0;
	char *duplicate_str;

	if (str_to_duplicate == NULL)
		return (NULL);
	while (*str_to_duplicate++)
		length++;
	duplicate_str = malloc(sizeof(char) * (length + 1));
	if (!duplicate_str)
		return (NULL);
	for (length++; length--;)
		duplicate_str[length] = *--str_to_duplicate;
	return (duplicate_str);

/**
 * print_string - function that prints an input string
 * @str_to_print: the string to print
 * Return: Null
 */

void print_string(char *str_to_print)
{
	int index = 0;

	if (!str_to_print)
		return;
	while (str_to_print[index] != '\0')
	{
		write_character(str_to_print[index]);
		index++;
	}
}

/**
 * write_character - function that writes a character to the standard output
 * @character: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and error no is set appropriately
 */
int write_character(char character)
{
static int buffer_index;
static char write_buffer[WRITE_BUFFER_SIZE];

if (character == FLUSH_BUFFER || buffer_index >= WRITE_BUFFER_SIZE)
{
	write(1, write_buffer, buffer_index);
	buffer_index = 0;
}
if (character != FLUSH_BUFFER)
{
	write_buffer[buffer_index++] = character;
	return (1);
}
}
