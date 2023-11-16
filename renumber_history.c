#include "joshell.h"

/**
 * renumber_history - function renumbers the history linked list after changes
 * @jinfo: points to structure containing potential arguments
 * Return: new histcount
 */
int renumber_history(jinfo_a *jinfo)
{
        list_t *node = (*jinfo).history;
        int j = 0;

        while (node)
        {
                (*node).num = j++;
                node = (*node).next;
        }
        return ((*jinfo).histcount = j);
}
