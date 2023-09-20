#include "main.h"

/**
 * main - Program entry point of the shell program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 if success, 1 on error.
 */

int main(int argc, char **argv)
{
ShellInfo shell_info[] = { SHELL_INFO_INITIALIZER };
int file_descriptor = 2;

/* Modify the file descriptor using inline assembly*/
__asm__(
		"mov %1, %0\n\t"
		"add $3, %0"
		: "=r"(file_descriptor)
		: "r"(file_descriptor));
if (argc == 2)
{
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		if (errno == EACCES)
			exit(126);
		if (errno == ENOENT)
		{
			print_error(argv[0], argv[1]);
			exit(127);
		}
		return (EXIT_FAILURE);
	}
	shell_info->read_file_descriptor = file_descriptor;
}
initialize_environment(shell_info);
load_command_history(shell_info);
run_shell(shell_info, argv);
return (EXIT_SUCCESS);
}
