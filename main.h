#ifndef MAIN_H
#define MAIN_H

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

#endif
