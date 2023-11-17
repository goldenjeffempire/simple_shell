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
#define JOMD_AND                2
#define JOMD_CHAIN      3
#define JOMD_N          0
#define JOMD_OR         1


/* for convert_number() */
#define JOCONV_LOW      1
#define JOCONV_UNS      2

/* 1 for default system getline() else use the custom _juseline */
#define JOUSE_GET 0

#define JOHIST_FILE     ".simple_shell_johistory"
#define JOHIST_MAX      4096

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
 *              allowing uniform prototype for function pointer struct
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
 *@alias: the alias node
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
        list_t *alias;
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
void find_cmd(jinfo_a *jinfo);
void fork_cmd(jinfo_a *jinfo);

/* jstr.c */
int _strlen(char *j);
int _strcmp(char *j1, char *j2);
char *_strcat(char *dest, char *src);
char *jstarts_with(const char *, const char *);
int _strcmp(char *, char *);

/* jmem-parse.c */
int jcmd(jinfo_a *jinfo, char *path);
char *joup_chars(char *pathjstr, int jstart, int jstop);
char *find_jpath(jinfo_a *, char *, char *);
int bfree(void **);

/* jerr.c */
void _jputs(char *jstr);
int _jputchar(char c);
int _jputjo(char c, int jo);
int _jerratoi(char *s);
int _jputsjo(char *str, int jo);

/* jerr2.c */
void print_error(jinfo_a *jinfo, char *jstr);
int print_d(int input, int jo);
void remove_comments(char *buf);
char *convert_number(long int num, int base, int jlags);

/* jstr2.c */
char *_strcpy(char *dest, char *src);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
char **strtow(char *, char *);

/* jfree.c */
char *_memset(char *t, char c, unsigned int o);
void jfree(char *p);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int interact(jinfo_a *jinfo);
int joelim(char d, char *josdelim);

/* joinfo.c */
void free_jinfo(jinfo_a *jinfo, int all);
void sigintHandler(__attribute__((unused))int sig_num);
void set_jinfo(jinfo_a *jinfo, char **av);
void clear_jinfo(jinfo_a *jinfo);

/* jcusbuilt.c */
int _jexit(jinfo_a *);
int _jcd(jinfo_a *);
int _jhelp(jinfo_a *);
int _myalias(jinfo_a *);

/* jbuilt.c */
int _history(jinfo_a *);
int print_alias(list_t *node);
int set_alias(jinfo_a *jinfo, char *jstr);

/* juseline.c */
ssize_t input_buf(jinfo_a *jinfo, char **buf, size_t *ten);
int _juseline(jinfo_a *, char **, size_t *);

/* jenv.c */
char *_juseenv(jinfo_a *jinfo, const char *name);
int _jenv(jinfo_a *jinfo);
int _jmsetenv(jinfo_a *);
int _junsetenv(jinfo_a *jinfo);
int jpop_env_list(jinfo_a *jinfo);

/* juseenv.c */
char **juse_env(jinfo_a *jinfo);
int j_unsetenv(jinfo_a *jinfo, char *jvar);
int _jsetenv(jinfo_a *jinfo, char *jvar, char *jvalue);

/* jhistory.c */
char *use_jhistory_file(jinfo_a *jinfo);
int write_jhistory(jinfo_a *jinfo);
ssize_t read_buf(jinfo_a *jinfo, char **buf, size_t *j);
int read_jhistory(jinfo_a *jinfo);
int build_jhistory_list(jinfo_a *jinfo, char *buf, int linecount);
int renumber_history(jinfo_a *jinfo);

/* jlists.c */
list_t *jadd_node(list_t **, const char *jstr, int numb);
list_t *jadd_node_end(list_t **, const char *jstr, int numb);
size_t jprint_list_str(const list_t *j);
ssize_t use_node_ind(list_t *hd, list_t *node)
int jdelete_node_at_ind(list_t **hd, unsigned int ind);
void jree_jlist(list_t **hd_jptr);

/* jlists2.c */
size_t jlist_len(const list_t *hd);
char **jlist_to_strings(list_t *hd);
size_t _jprintlist(const list_t *hd);
list_t *jnode_starts_with(list_t *node, char *prefix, char cd);
ssize_t use_node_ind(list_t *, list_t *);

/* jchain.c */
int jchain(jinfo_a *jinfo, char *buf, size_t *f);
void check_chain(jinfo_a *jinfo, char *buf, size_t *f, size_t i, size_t len);
int replace_alias(jinfo_a *);
int replace_vars(jinfo_a *jinfo);
int replace_string(char **old, char *new);

/* jexit.c */
char *_strncpy(char *dest, char *src, int o);
char *_strncat(char *dest, char *src, int o);
char *_strchr(char *s, char e);
int _strncmp(const char *j1, const char *j2, size_t o);

#endif /* JOSHELL_H */
