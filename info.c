#include "joshell.h"

/**
 * clear_jinfo - function initializes jinfo_a struct
 * @jinfo: struct address
 */
void clear_jinfo(jinfo_a *jinfo)
{
        (*jinfo).arg = NULL;
        (*jinfo).argv = NULL;
        (*jinfo).path = NULL;
        (*jinfo).argc = 0;
}

/**
 * set_jinfo - function initializes jinfo_a struct
 * @jinfo: struct address
 * @av: argument vector with double pointer
 */
void set_jinfo(jinfo_a *jinfo, char **av)
{
        int i = 0;

        (*jinfo).fname = av[0];
        if ((*jinfo).arg)
        {
                (*jinfo).argv = strtow((*jinfo).arg, " \t");
                if (!(*jinfo).argv)
                {

                        (*jinfo).argv = malloc(sizeof(char *) * 2);
                        if ((*jinfo).argv)
                        {
                                (*jinfo).argv[0] = _strdup((*jinfo).arg);
                                (*jinfo).argv[1] = NULL;
                        }
                }
                for (i = 0; (*jinfo).argv && (*jinfo).argv[i]; i++)
                        ;
                (*jinfo).argc = i;

                replace_alias(jinfo);
                replace_vars(jinfo);
        }
}

/**
 * free_jinfo - function frees jinfo_a struct fields
 * @info: struct address
 * @all: true parameter
 */
void free_jinfo(jinfo_a *jinfo, int all)
{
        free((*jinfo).argv);
        (*jinfo).argv = NULL;
        (*jinfo).path = NULL;
        if (all)
        {
                if (!(*jinfo).cmd_buf)
                        jfree((*jinfo).arg);
                if ((*jinfo).env)
                        jree_jlist(&((*jinfo).env));
                if ((*jinfo).history)
                        jree_jlist(&((*jinfo).history));
                if ((*jinfo).alias)
                        jree_jlist(&((*jinfo).alias));
                free((*jinfo).environ);
                        (*jinfo).environ = NULL;
                bfree((void **)(*jinfo).cmd_buf);
                if ((*jinfo).readjo > 2)
                        close((*jinfo).readjo);
                _putchar(JOBUF_JOLUSH);
        }
}

/**
 * sigintHandler - function blocks ctrl-C
 * @sig_num: the signal number
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
        _puts("\n");
        _puts("$ ");
        _putchar(JOBUF_JOLUSH);
}
