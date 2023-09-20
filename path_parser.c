#include "main.h"

/**
 * isExecutableCommand - function that determines if a file is an
 * executable command
 * @info: The info struct (not used in this function)
 * @path: Path to the file
 *
 * This function checks if a file exists at the specified 'path' and if it has
 * the S_IFREG (regular file) mode set, indicating that it is an executable
 * command
 *
 * Return: 1 if 'path' points to an executable command, 0 otherwise.
 */

int isExecutableCommand(info_t *info, char *path)
{
struct stat st;
(void)info;/* Unused parameter */

if (!path || stat(path, &st) != 0)
	return (0);
return ((st.st_mode & S_IFREG) ? 1 : 0);
}

/**
 * duplicateSubstring - function that duplicates characters
 * from 'pathstr' based on indices
 * @pathstr: The PATH string
 * @start: Starting index
 * @stop: Stopping index
 *
 * The function duplicates characters from 'pathstr' between 'start' and 'stop'
 * indices (excluding ':')into a new buffer and returns a pointer to the buffer
 *
 * Return: Pointer to a new buffer containing the duplicated characters
 */

char *duplicateSubstring(char *pathstr, int start, int stop)
{
static char buffer[1024];
int i = 0, k = 0;

for (k = 0, i = start; i < stop; i++)
{
	if (pathstr[i] != ':')
		buffer[k++] = pathstr[i];
}
buffer[k] = '\0';
return (buffer);
}

/**
 * findExecutableInPath - function that finds the full
 * path of a command in the PATH variable
 * @info: The info struct (not used in this function)
 * @pathstr: The PATH string
 * @cmd: The command to find
 *
 * This function searches for the 'cmd' in the 'pathstr' by
 * splitting it using ':' as a delimiter. It constructs potential
 * full paths by combining 'cmd' with each directory in 'pathstr'
 * and checks if the resulting path points to an executable
 * command using 'isExecutableCommand'
 *
 * Return: The full path of 'cmd' if found, or NULL if not found
 */

char *findExecutableInPath(info_t *info, char *pathstr, char *cmd)
{
int i = 0, curr_pos = 0;
char *path;

if (!pathstr)
	return (NULL);
if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
{
	if (isExecutableCommand(info, cmd))
		return (cmd);
}
while (1)
{
	if (!pathstr[i] || pathstr[i] == ':')
	{
		path = duplicateSubstring(pathstr, curr_pos, i);
		if (!*path)
			_strcat(path, cmd);
		else
		{
			_strcat(path, "/");
			_strcat(path, cmd);
		}
		if (isExecutableCommand(info, path))
			return (path);
		if (!pathstr[i])
			break;
		curr_pos = i;
	}
	i++;
}
return (NULL);
}
