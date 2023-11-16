#include "joshell.h"

/**
 * replace_alias - function replaces an faliases in the tokenized string
 * @jinfo: the parameter struct pointer
 * Return: 1 if replaced, else 0
 */
int replace_alias(jinfo_a *jinfo)
{
        int i;
        list_t *node;
        char *j;

        for (i = 0; i < 10; i++)
        {
                node = jnode_starts_with((*jinfo).alias, (*jinfo).argv[0], '=');
                if (!node)
                        return (0);
                free((*jinfo).argv[0]);
                j = _strchr((*node).jstr, '=');
                if (!j)
                        return (0);
                j = _strdup(j + 1);
                if (!j)
                        return (0);
                (*jinfo).argv[0] = j;
        }
        return (1);
}
