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

/* 1 for default system getline() else use the custom _juseline */
#define JOUSE_GET 0

#define JOHIST_FILE	".simple_shell_johistory"
#define JOHIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @jstr: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *jstr;
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
 *@readjo: the jo from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	char **environ;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	int status;
	list_t *history;
	list_t *falias;
	int env_changed;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readjo;
	int histcount;
} jinfo_a;

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
	int (*func)(jinfo_a *);
} builtin_table;


/* jshell_start.c */
int hsh(jinfo_a *, char **);
int find_builtin(jinfo_a *);
void find_cmd(jinfo_a *);
void fork_cmd(jinfo_a *);

/* jstr.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *_strcat(char *, char *);
char *jstarts_with(const char *, const char *);
int _strcmp(char *, char *);

/* jmem-parse.c */
int jcmd(jinfo_a *, char *);
char *jdup_chars(char *, int, int);
char *find_jpath(jinfo_a *, char *, char *);
int bfree(void **);

/* jerr.c */
void _jputs(char *);
int _jputchar(char);
int _jputjo(char c, int jo);
int _jerratoi(char *);
int _jputsjo(char *jstr, int jo);

/* jerr2.c */
void print_error(jinfo_a *, char *);
int print_d(int, int);
void remove_comments(char *);
char *convert_number(long int, int, int);

/* jstr2.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
char **strtow(char *, char *);

/* jfree.c */
char *_memset(char *, char, unsigned int);
void jfree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int interact(jinfo_a *);
int joelim(char, char *);

/* joinfo.c */
void free_jinfo(jinfo_a *, int);
void sigintHandler(int);
void set_jinfo(jinfo_a *, char **);
void clear_jinfo(jinfo_a *);

/* jcusbuilt.c */
int _jexit(jinfo_a *);
int _jcd(jinfo_a *);
int _jhelp(jinfo_a *);
int _myfalias(jinfo_a *);

/* jbuilt.c */
int _jhistory(jinfo_a *);
int print_falias(list_t *node);
int set_falias(jinfo_a *jinfo, char *jstr);

/* juseline.c */
ssize_t use_input(jinfo_a *);
int _juseline(jinfo_a *, char **, size_t *);

/* jenv.c */
char *_juseenv(jinfo_a *, const char *);
int _jenv(jinfo_a *);
int _jmsetenv(jinfo_a *);
int _junsetenv(jinfo_a *);
int jpop_env_list(jinfo_a *);

/* juseenv.c */
char **juse_env(jinfo_a *);
int j_unsetenv(jinfo_a *, char *);
int _jsetenv(jinfo_a *, char *, char *);

/* jhistory.c */
char *use_jhistory_file(jinfo_a *jinfo);
int write_jhistory(jinfo_a *jinfo);
int read_jhistory(jinfo_a *jinfo);
int build_jhistory_list(jinfo_a *jinfo, char *buf, int linecount);
int renumber_history(jinfo_a *jinfo);

/* jlists.c */
list_t *jadd_node(list_t **, const char *, int);
list_t *jadd_node_end(list_t **, const char *, int);
size_t jprint_list_str(const list_t *);
int jdelete_node_at_ind(list_t **, unsigned int);
void jree_jlist(list_t **);

/* jlists2.c */
size_t jlist_len(const list_t *);
char **jlist_to_strings(list_t *);
size_t _jprintlist(const list_t *);
list_t *jnode_starts_with(list_t *, char *, char);
ssize_t use_node_ind(list_t *, list_t *);

/* jchain.c */
int jchain(jinfo_a *, char *, size_t *);
void check_jchain(jinfo_a *, char *, size_t *, size_t, size_t);
int replace_falias(jinfo_a *);
int replace_jvars(jinfo_a *);
int replace_jstring(char **, char *);

/* jexit.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

#endif /* JOSHELL_H */
