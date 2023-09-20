#include "main.h"

/**
 * _input - buffers chained commands
 * @inf: parameter struct
 * @buff: address of buffer
 * @l: address of len var
 *
 * Return: bytes read
 */
ttype_size _input(type_info *inf, char **buff, size_t *l)
{
	ttype_size a = 0;
	ttype_size pl = 0;

	if (!*l)
	{
		free(*buff);
		*buff = NULL;
		signal(SIGINT, sigintHandler);
#if _GETLINE
		a = getline(buf, &pl, stdin);
#else
		a = nextline(inf, buff, &pl);
#endif
		if (a > 0)
		{
			if ((*buff)[a - 1] == '\n')
			{
				(*buff)[a - 1] = '\0';
				a--;
			}
			inf->count_flag = 1;
			comment_rm(*buff);
			add_histentry(inf, *buff, inf->cnt_hist++);
			{
				*l = a;
				inf->bf_cmd = buff;
			}
		}
	}
	return (a);
}

/**
 * buff_read - reads a buffer
 * @inf: parameter struct
 * @buff: buffer
 * @s: size
 * Return: a
 */
ttype_size buff_read(type_info *inf, char *buff, size_t *s)
{
	ttype_size a = 0;

	if (*s)
		return (0);
	a = read(inf->readfd, buff, BUFF_READ_SIZE);
	if (a >= 0)
		*s = a;
	return (a);
}

/**
 * nextline - gets the next line of input from STDIN
 * @inf: parameter struct
 * @pt: address of pointer to buffer preallocated or NULL
 * @l: size of preallocated ptr buffer if not NULL
 * Return: n
 */
int nextline(type_info *inf, char **pt, type_size *l)
{
	static char buff[BUFF_READ_SIZE];
	static type_size a, len;
	type_size b;
	ttype_size r = 0, n = 0;
	char *p = NULL, *p2 = NULL, *c;

	p = *pt;
	if (p && l)
		n = *l;
	if (a == len)
		a = len = 0;

	r = read_buf(info, buff, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = loc_chr(buff + a, '\n');
	b = c ? 1 + (unsigned int)(c - buff) : len;
	p2 = _realloc(p, n, n ? n + b : b + 1);
	if (!p2)
		return (p ? free(p), -1 : -1);

	if (n)
		stcat(p2, buf + a, b - a);
	else
		stcpy(p2, buf + a, b - a + 1);

	n += b - a;
	a = b;
	p = p2;

	if (l)
		*l = n;
	*pt = p;
	return (n);
}

/**
 * typ_in - gets line minus newline
 * @inf: parameter struct
 * Return: bytes read
 */
ttype_size typ_in(type_info *inf)
{
	static char *buff;
	static type_size a, b, l;
	ttype_size_t r = 0;
	char **buff_p = &(info->arg), *p;

	print_out(BUFF_FLUSH);
	r = _input(inf, &buff, &l);
	if (r == -1)
		return (-1);
	if (l)
	{
		b = a;
		p = buff + a;

		_chainchk(inf, buff, &b, a, l);
		while (b < l)
		{
			if (chain_del(inf, buff, &b))
				break;
			b++;
		}

		a = b + 1;
		if (a >= l)
		{
			a = l = 0;
			inf->bf_cmdtype = CMD_NORM;
		}

		*buff_p = p;
		return (stlen(p));
	}

	*buff_p = buff;
	return (r);
}

/**
 * block_ctc - blocks ctrl-C
 * @num: the signal number
 * Return: void
 */
void block_ctc(__attribute__((unused))int num)
{
	p_string("\n");
	p_string("$ ");
	print_out(BUFF_FLUSH);
}
