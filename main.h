#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


/* _atoi.c */
int is_delimiter(char ch, char *delim);
int _isalphabetic(int ch);
int _atoi(char *s);

/* builtins.c */
int _shellexit(info_t *info);
int _change_directory(info_t *info);
int _shellhelp(info_t *info);

/* builtins_2.c */
int display_command_history(info_t *info);
int remove_alias(info_t *info, char *alias_string);
int add_alias(info_t *info, char *alias_string);
int print_single_alias(alias_t *alias_node);
int manage_aliases(info_t *info);

/* environment_var.c */
int display_environment(info_t *info);
char *get_environment_variable(info_t *info, const char *name);
int set_environment_variable(info_t *info);
int unset_environment_variable(info_t *info);
int populate_environment_list(info_t *info);

/* string_handling.c */
int string_length(char *str);
int string_compare(char *str1, char *str2);
char *string_starts_with(const char *haystack, const char *needle);
char *string_concatenate(char *destination, char *source);

/* string_handling2.c */
char *string_copy(char *destination, char *source);
char *string_duplicate(const char *str_to_duplicate);
void print_string(char *str_to_print);

/* string_handling2.c */
int write_character(char ch);

/* token_generator.c */
char **split_string_by_delimiters(char *str, char *d);
char **split_string_by_single_delimiter(char *input_str, char delim);

/* variables.c */
int is_chain_delimiter(info_t *info, char *buffer, size_t *position);
void check_chain_continue(info_t *info, char *buffer,
size_t *position, size_t start_position, size_t length);
int replace_aliases(info_t *info);
int replace_variables(info_t *info);
int replace_string(char **old_str, char *new_str);

/* main.c */
int main(int argc, char **argv);

/* path_parser.c */
int isExecutableCommand(info_t *info, char *path);
char *duplicateSubstring(char *pathstr, int start, int stop);
char *findExecutableInPath(info_t *info, char *pathstr, char *cmd);

/* shell_loop.c */
int shellMainLoop(info_t *info, char **av);
int findBuiltinCommand(info_t *info);
void findExecutableCommand(info_t *info);
void forkAndExecuteCommand(info_t *info);

/* handle input */
void p_string(char *s);
int pfd_string(char *s, int fd);
int pr_error(char c);

int wri_fd(char c, int fd);
int atoi_er(char *st);
void perr_msg(info_type *inf, char *est);
int handle_d(int in, int fd);
char *num_convert(long int nu, int ba, int fl);
void comment_rm(char *buff);
char *stcat(char *dest, char *src, int byte);
char *stcpy(char *dest, char *src, int total);
char *loc_chr(char *str, char ch);
char **fin_env(type_info *inf);
int reset_env(type_info *inf, char *v);
int set_env(type_info *inf, char *v, char *value);
ttype_size _input(type_info *inf, char **buff, size_t *l);
ttype_size buff_read(type_info *inf, char *buff, size_t *s);
int nextline(type_info *inf, char **pt, type_size *l);
ttype_size typ_in(type_info *inf);
void block_ctc(__attribute__((unused))int num);

/* info functions */
void startinfo(type_info *info);
void initinfo(type_info *inf, char **av);
void resetinfo(type_info *inf, int f);

/* History functions */
char *hist_file(type_info *inf);
int hist_write(type_info *inf);
int hist_read(type_info *inf);
int history_build(type_info *inf, char *buff, int lcount);
int hist_renum(type_info *inf);

/* memory functions */
char *set_mem(char *p, char byte, unsigned int b);
void free_str(char **p_st);
int free_p(void **p);
void *re_alloc(void *p, unsigned int size, unsigned int size_new);

/* lists functions */
type_size p_list_str(const type_list *h);
type_size lenlist(const type_list *h);
type_size pr_list(const type_list *h);
char **list_str(type_list *h);
void listfree(type_list **head_p);

type_list *node_add(type_list **h, const char *s, int num);
type_list *nodeadd_end(type_list **h, const char *s, int num);
int node_delete(type_list **h, unsigned int ind);
type_list *start_node(type_list *n, char *pre, char ch);
ttype_size node_index(type_list *h, type_list *n);

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUFF_FLUSH -1

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define FILE_HIST	".simple_shell_history"
#define MAX_HIST	4096

extern char **envi;

/**
 * struct stlist - singly linked list
 * @n: the number field
 * @s: a string
 * @next: points to the next node
 */
typedef struct stlist
{
	int n;
	char *s;
	struct stlist *next;
} type_list;

/**
 * struct infopas - contains pseudo-arguements to pass into a function
 * @arg: string generated from getline containing arguements
 * @argv:an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @counterr: the error count
 * @num_err: error code for exit()s
 * @count_flag: if on count this line of input
 * @f_name: the program filename
 * @env: linked list local copy of environ
 * @envi: custom modified copy of environ from LL env
 * @nhistory: the history node
 * @lias: alias node
 * @ch_env: on if environ changed
 * @status: return status of last exec'd command
 * @bf_cmd: address of pointer to bf_cmd
 * @bf_cmdtype: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @cnt_hist: history line number count
 */
typedef struct infopas
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int lcount;
	int num_err;
	int count_flag;
	char *f_name;
	type_list *env;
	type_list *nhistory;
	type_list *lias;
	char **envi;
	int ch_env;
	int status;

	char **bf_cmd;
	int bf_cmdtype;
	int readfd;
	int count;
} type_info;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct info_built - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct info_built
{
	char *type;
	int (*func)(type_info *);
} info_builtin;

#endif
