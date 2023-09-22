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
		if (!inf->bf_cmd)
			free(inf->arg);
		if (inf->env)
			fr_list(&(inf->env));
		if (inf->history)
			fr_list(&(inf->history));
		if (inf->alias)
			fr_list(&(inf->lias));
		free_str(inf->envi);
			inf->envi = NULL;
		free_p((void **)inf->bf_cmd);
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
	int a = 0;

	inf->f_name = av[0];
	if (inf->arg)
	{
		inf->argv = split_str(inf->arg, "\t");
		if (!inf->argv)
		{
			inf->argv = malloc(sizeof(char *) * 2);
			if (inf->argv)
			{
				inf->argv[0] = dup_s(inf->arg);
				inf->argv[1] = NULL;
			}
		}
		for (a = 0; inf->argv && inf->argv[a]; a++)
			;
		inf->argc = a;

		alias_rep(inf);
		vars_rep(inf);
	}
}
