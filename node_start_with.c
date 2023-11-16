#include "joshell.h"

/**
 * node_starts_with - function returns node whose string starts with prefix
 * @node: pointer to list hd
 * @prefix: pointer string to match
 * @cd: the next character after prefix to match
 * Return: NULL
 */
list_t *node_starts_with(list_t *node, char *prefix, char cd)
{
        char *j = NULL;

        while (node)
        {
                j = jstarts_with((*node).jstr, prefix);
                if (j && ((cd == -1) || (*j == cd)))
                        return (node);
                node = (*node).next;
        }
        return (NULL);
}
