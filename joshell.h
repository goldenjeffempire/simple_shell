#ifndef JOSHELL_H
#define JOSHELL_H

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

/* for read/write buffers */
#define JOBUF_SIZE 1024
#define JOBUF_JOLUSH -1

/* for command chaining */
#define JOMD_AND		2
#define JOMD_CHAIN	3
#define JOMD_N		0
#define JOMD_OR		1


/* for convert_number() */
#define JOCONV_LOW	1
#define JOCONV_UNS	2

/* 1 for default system getline() else use the custom _fgetline */
#define JOUSE_GET 0

#define JOHIST_FILE	".simple_shell_johistory"
#define JOHIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @fstr: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *fstr;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@falias: the falias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *falias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} finfo_a;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(finfo_a *);
} builtin_table;


/* fshell_start.c */
int hsh(finfo_a *, char **);
int find_builtin(finfo_a *);
void find_cmd(finfo_a *);
void fork_cmd(finfo_a *);

/* fmem-parse.c */
int fcmd(finfo_a *, char *);
char *fdup_chars(char *, int, int);
char *find_fpath(finfo_a *, char *, char *);
int bfree(void **);

/* ferr.c */
void _fputs(char *);
int _fputchar(char);
int _fputfd(char c, int fd);
int _fputsfd(char *fstr, int fd);
int _ferratoi(char *);

/* fstr.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *fstarts_with(const char *, const char *);
char *_strcat(char *, char *);

/* fstr2.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
char **strtow(char *, char *);

/* fexit.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* ffree.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int interact(finfo_a *);
int fdelim(char, char *);

/* ferr2.c */
void print_error(finfo_a *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* fcusbuilt.c */
int _fexit(finfo_a *);
int _fcd(finfo_a *);
int _fhelp(finfo_a *);
int _myfalias(finfo_a *);

/* fbuilt.c */
int _fhistory(finfo_a *);
int print_falias(list_t *node);
int set_falias(finfo_a *finfo, char *fstr);

/* fgetline.c */
ssize_t get_input(finfo_a *);
int _fgetline(finfo_a *, char **, size_t *);


/* fainfo.c */
void sigintHandler(int);
void clear_finfo(finfo_a *);
void set_finfo(finfo_a *, char **);
void free_finfo(finfo_a *, int);

/* fenv.c */
char *_fgetenv(finfo_a *, const char *);
int _fenv(finfo_a *);
int _fmsetenv(finfo_a *);
int _funsetenv(finfo_a *);
int fpop_env_list(finfo_a *);

/* fgetenv.c */
char **fget_env(finfo_a *);
int f_unsetenv(finfo_a *, char *);
int _fsetenv(finfo_a *, char *, char *);

/* fhist.c */
char *get_fhistory_file(finfo_a *finfo);
int write_fhistory(finfo_a *finfo);
int read_fhistory(finfo_a *finfo);
int build_fhistory_list(finfo_a *finfo, char *buf, int linecount);
int renumber_history(finfo_a *finfo);

/* flist.c */
list_t *fadd_node(list_t **, const char *, int);
list_t *fadd_node_end(list_t **, const char *, int);
size_t fprint_list_str(const list_t *);
int fdelete_node_at_ind(list_t **, unsigned int);
void free_flist(list_t **);

/* flists2.c */
size_t flist_len(const list_t *);
char **flist_to_strings(list_t *);
size_t _fprintlist(const list_t *);
list_t *fnode_starts_with(list_t *, char *, char);
ssize_t get_node_ind(list_t *, list_t *);

/* fchain.c */
int fchain(finfo_a *, char *, size_t *);
void check_fchain(finfo_a *, char *, size_t *, size_t, size_t);
int replace_falias(finfo_a *);
int replace_fvars(finfo_a *);
int replace_fstring(char **, char *);

#endif /* FASHELL_H */
