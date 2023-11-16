#include "joshell.h"

/**
 * read_buf - this function reads a buffer
 * @jinfo: parameter struct
 * @buf: buffer pointer
 * @j: size parameter
 * Return: t
 */
ssize_t read_buf(jinfo_a *jinfo, char *buf, size_t *j)
{
        ssize_t t = 0;

        if (*j)
                return (0);
        t = read((*jinfo).readjo, buf, JOBUF_SIZE);
        if (t >= 0)
                *j = t;
        return (t);
}

/**
 * write_jhistory - function creates a file / appends to an existing file
 * @jinfo: the parameter struct
 * Return: 1 if successful, else -1
 */
int write_jhistory(jinfo_a *jinfo)
{
        ssize_t jo;
        char *filename = use_jhistory_file(jinfo);
        list_t *node = NULL;

        if (!filename)
                return (-1);

        jo = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
        jfree(filename);
        if (jo == -1)
                return (-1);
        for (node = (*jinfo).history; node; node = (*node).next)
        {
                _jputsjo((*node).jstr, jo);
                _jputjo('\n', jo);
        }
        _jputjo(JOBUF_JOLUSH, jo);
        close(jo);
        return (1);
}
