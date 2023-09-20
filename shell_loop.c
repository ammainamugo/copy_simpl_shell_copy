#include "main.h"

/**
 * shellMainLoop - Main loop of the shell program
 * @info: The parameter & return info struct
 * @av: The argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */

int shellMainLoop(info_t *info, char **av)
{
ssize_t read_result = 0;
int builtin_result = 0;

while (read_result != -1 && builtin_result != -2)
{
	clearInfoStruct(info);
	if (isInteractive(info))
		_puts("$ ");
	_eputchar(BUF_FLUSH);
	read_result = getInput(info);
	if (read_result != -1)
	{
		setInfo(info, av);
		builtin_result = findBuiltinCommand(info);
		if (builtin_result == -1)
			findExecutableCommand(info);
	}
	else if (isInteractive(info))
		_putchar('\n');
	freeInfoStruct(info, 0);
}
writeCommandHistory(info);
freeInfoStruct(info, 1);
if (!isInteractive(info) && info->status)
	exit(info->status);
if (builtin_result == -2)
{
	if (info->err_num == -1)
		exit(info->status);
	exit(info->err_num);
}
return (builtin_result);
}

/**
 * findBuiltinCommand - function that finds a builtin command
 * @info: The parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *         0 if builtin executed successfully,
 *         1 if builtin found but not successful,
 *         2 if builtin signals exit()
 */

int findBuiltinCommand(info_t *info)
{
int i, builtin_result = -1;

builtin_table builtintbl[] = {
	{"exit", myExit},
	{"env", myEnv},
	{"help", myHelp},
	{"history", myHistory},
	{"setenv", mySetEnv},
	{"unsetenv", myUnsetEnv},
	{"cd", myCd},
	{"alias", myAlias},
	{NULL, NULL}
};
for (i = 0; builtintbl[i].type; i++)
{
	if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
	{
		info->line_count++;
		builtin_result = builtintbl[i].func(info);
		break;
	}
}
return (builtin_result);
}

/**
 * findExecutableCommand - function that finds a command in the PATH
 * @info: The parameter & return info struct
 *
 * Return: void
 */

void findExecutableCommand(info_t *info)
{
char *path = NULL;
int i, k;

info->path = info->argv[0];
if (info->linecount_flag == 1)
{
	info->line_count++;
	info->linecount_flag = 0;
}
for (i = 0, k = 0; info->arg[i]; i++)
{
	if (!isDelimiter(info->arg[i], " \t\n"))
		k++;
}
if (!k)
	return;
	path = findCommandInPath(info, _getenv(info, "PATH="), info->argv[0]);
if (path)
{
	info->path = path;
	forkAndExecuteCommand(info);
}
else
{
	if ((isInteractive(info) || _getenv(info, "PATH=") || info->argv[0][0] == '/')
			&& isExecutableCommand(info, info->argv[0]))
		forkAndExecuteCommand(info);
	else if (*(info->arg) != '\n')
	{
		info->status = 127;
		printError(info, "not found\n");
	}
}
}

/**
 * forkAndExecuteCommand - function that forks and executes a command
 * @info: The parameter & return info struct
 *
 * Return: void
 */

void forkAndExecuteCommand(info_t *info)
{
pid_t child_pid;
child_pid = fork();

if (child_pid == -1)
{
	/* TODO: PUT ERROR FUNCTION */
	perror("Error:");
	/* return; */
}
if (child_pid == 0)
{
	if (execve(info->path, info->argv, getEnviron(info)) == -1)
	{
		freeInfoStruct(info, 1);
		if (errno == EACCES)
			exit(126);
		exit(1);
	}
	/* TODO: PUT ERROR FUNCTION */
}
else
{
	wait(&(info->status));
	if (WIFEXITED(info->status))
	{
		info->status = WEXITSTATUS(info->status);
		if (info->status == 126)
			printError(info, "Permission denied\n");
	}
}
}
