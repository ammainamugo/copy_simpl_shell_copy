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
int write_character(char character);

/* token_generator.c */
char **split_string_by_delimiters(char *input_str, char *delim_str);
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

/* ptr_memory.c */
int freeAndNullPointer(void **ptr);

/* path_parser.c */
int isExecutableCommand(info_t *info, char *path);
char *duplicateSubstring(char *pathstr, int start, int stop);
char *findExecutableInPath(info_t *info, char *pathstr, char *cmd);

/* shell_loop.c */
int shellMainLoop(info_t *info, char **av);
int findBuiltinCommand(info_t *info);
void findExecutableCommand(info_t *info);
void forkAndExecuteCommand(info_t *info);

void p_string(char *s);
int pfd_string(char *s, int fd);
int pr_error(char c);
int wri_fd(char c, int fd);
int atoi_er(char *st);
void perr_msg(info_type *inf, char *est);
int handle_d(int in, int fd);
char *_itoa(long int nu, int ba, int fl);
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
void startinfo(type_info *info);
void initinfo(type_info *inf, char **av);
void resetinfo(type_info *inf, int f);
char *hist_file(type_info *inf);
int hist_write(type_info *inf);
int hist_read(type_info *inf);
int history_build(type_info *inf, char *buff, int lcount);
int hist_renum(type_info *inf);
type_list *node_add(type_list **h, const char *s, int num);
type_list *nodeadd_end(type_list **h, const char *s, int num);
type_size p_list_str(const type_list *h);
int node_delete(type_list **h, unsigned int ind);
void listfree(type_list **head_p);
type_size lenlist(const type_list *h);
char **list_str(type_list *h);
type_size pr_list(const type_list *h);
type_list *node_starts_with(type_list *n, char *pre, char ch);
ttype_size node_index(type_list *h, type_list *n);


#endif
