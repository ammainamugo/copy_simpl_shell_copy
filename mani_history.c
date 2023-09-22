#include "main.h"

/**
 * hist_file - gets history file
 * @inf: parameter struct
 * Return: allocated string containg history file
 */
char *hist_file(type_info *inf)
{
	char *buff, *d;

	d = _getenv(inf, "HOME=");
	if (!d)
		return (NULL);
	buff = malloc(sizeof(char) * (stlen(d) + stlen(FILE_HIST) + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	stcopy(buff, d);
	stccat(buff, "/");
	stccat(buff, FILE_HIST);
	return (buff);
}

/**
 * hist_read - reads history from file
 * @inf: the parameter struct
 * Return: count on success, 0 otherwise
 */
int hist_read(type_info *inf)
{
	int a, last = 0, lcount = 0;
	ttype_size fd, rdlen, fsize = 0;
	struct stat s;
	char *buff = NULL, *f_name = hist_file(inf);

	if (!f_name)
		return (0);

	fd = open(f_name, O_RDONLY);
	free(f_name);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &s))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buff = malloc(sizeof(char) * (fsize + 1));
	if (!buff)
		return (0);
	rdlen = read(fd, buff, fsize);
	buff[fsize] = 0;
	if (rdlen <= 0)
		return (free(buff), 0);
	close(fd);
	for (a = 0; a < fsize; a++)
		if (buff[a] == '\n')
		{
			buff[a] = 0;
			history_build(inf, buff + last, lcount++);
			last = a + 1;
		}
	if (last != a)
		history_build(inf, buff + last, lcount++);
	free(buff);
	info->count = lcount;
	while (inf->count-- >= MAX_HIST)
		node_delete(&(inf->nhistory), 0);
	hist_renum(inf);
	return (inf->count);
}

/**
 * hist_write - creates a file, or appends to an existing file
 * @inf: the parameter struct
 * Return: 1 on success, else -1
 */
int hist_write(type_info *inf)
{
	ttype_size fd;
	char *f_name = hist_file(inf);
	type_list *node = NULL;

	if (!f_name)
		return (-1);

	fd = open(f_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(f_name);
	if (fd == -1)
		return (-1);
	for (node = inf->nhistory; node; node = node->next)
	{
		pfd_string(node->s, fd);
		wri_fd('\n', fd);
	}
	wri_fd(BUFF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * hist_renum - renumbers history linked list after changes
 * @inf: Structure containing potential arguments used to maintain
 * Return: new hcount
 */
int hist_renum(type_info *inf)
{
	type_list *node = inf->nhistory;
	int a = 0;

	while (node)
	{
		node->n = a++;
		node = node->next;
	}
	return (inf->count = a);
}

/**
 * history_build - adds entry to a history linked list
 * @inf: Structure containing potential arguments used to maintain
 * @buff: buffer
 * @lcount: the history linecount, histcount
 * Return: Always 0
 */
int history_build(type_info *inf, char *buff, int lcount)
{
	type_list *node = NULL;

	if (inf->nhistory)
		node = inf->nhistory;
	nodeadd_end(&node, buff, lcount);

	if (!inf->nhistory)
		inf->nhistory = node;
	return (0);
}
