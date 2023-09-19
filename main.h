#ifndef MAIN_H
#define MAIN_H

int sh_mode(type_info *sh_info);
int find_delim(char ch, char *d);
int find_alpha(int ch);

void p_string(char *s);
int pfd_string(char *s, int fd);
int pr_error(char c);
int wri_fd(char c, int fd);
int atoi_er(char *st);
void perr_msg(info_type *inf, char *est);
int handle_d(int in, int fd);
char *_itoa(long int nu, int ba, int fl);
void comment_rm(char *buff);

#endif
