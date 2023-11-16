#include "joshell.h"

/**
 * build_history_list - funtion thta adds entry to a history linked-list
 * @jinfo:this contains argument that is used to manage
 * @buf: buffer pointer
 * @linecount: the history linecount and histcount
 * Return: Always 0
 */
int build_history_list(jinfo_a *jinfo, char *buf, int linecount)
{
        list_t *node = NULL;

        if ((*jinfo).history)
                node = (*jinfo).history;
        jadd_node_end(&node, buf, linecount);

        if (!(*jinfo).history)
                (*jinfo).history = node;
        return (0);
}
