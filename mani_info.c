#include "main.h"

/**
 * startinfo - initializes typeinfo struct
 * @inf: struct address
 */
void startinfo(type_info *inf)
{
	inf->arg = NULL;
	inf->argv = NULL;
	inf->path = NULL;
	inf->argc = 0;
}

/**
 * resetinfo - frees type_info struct fields
 * @inf: struct address
 * @f: true if freeing all fields
 */
void resetinfo(type_info *inf, int f)
{
	free_str(inf->argv);
	inf->argv = NULL;
	inf->path = NULL;
	if (f)
	{
		if (!inf->bf_cmdtype)
			free(inf->arg);
		if (inf->env)
			fr_list(&(inf->env));
		if (inf->history)
			fr_list(&(inf->history));
		if (inf->alias)
			fr_list(&(inf->alias));
		free_str(inf->environ);
			inf->environ = NULL;
		bfree((void **)inf->bf_cmdtype);
		if (inf->readfd > 2)
			close(inf->readfd);
		print_out(BUFF_FLUSH);
	}
}

/**
 * initinfo - initializes type_info struct
 * @inf: struct address
 * @av: argument vector
 */
void initinfo(type_info *inf, char **av)
{
	int i = 0;

	inf->fname = av[0];
	if (inf->arg)
	{
		inf->argv = strtow(inf->arg, " \t");
		if (!inf->argv)
		{
			inf->argv = malloc(sizeof(char *) * 2);
			if (inf->argv)
			{
				inf->argv[0] = _strdup(inf->arg);
				inf->argv[1] = NULL;
			}
		}
		for (i = 0; inf->argv && inf->argv[i]; i++)
			;
		inf->argc = i;

		replace_alias(inf);
		replace_vars(inf);
	}
}
