#include "joshell.h"

/**
 * input_buf -function that buffers chained commands
 * @jinfo: parameter struct
 * @buf: double pointer to the address of buffer
 * @ten: address of ten var
 * Return: bytes
 */
ssize_t input_buf(jinfo_a *jinfo, char **buf, size_t *ten)
{
        ssize_t t = 0;
        size_t ten_p = 0;

        if (!*ten)
        {
                jfree(*buf);
                *buf = NULL;
                signal(SIGINT, sigintHandler);
#if USE_FUSE
                 = useline(buf, &ten_p, stdin);
#else
                t = _juseline(jinfo, buf, &ten_p);
#endif
                if (t > 0)
                {
                        if ((*buf)[t - 1] == '\n')
                        {
                                (*buf)[t - 1] = '\0';
                                t--;
                        }
                        (*jinfo).linecount_flag = 1;
                        remove_comments(*buf);
                        build_jhistory_list(jinfo, *buf, (*jinfo).histcount++);
                        {
                                *ten = t;
                                (*jinfo).cmd_buf = buf;
                        }
                }
        }
        return (t);
}
