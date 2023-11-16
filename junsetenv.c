#include "joshell.h"

/**
 * j_unsetenv - this function removes an environment variable
 * @jinfo: points to structure containing potential arguments and
 * used to maintain constant function prototype.
 * @jvar: the string env var property
 *  Return: 1 if delete, else 0
 */
int j_unsetenv(jinfo_a *jinfo, char *jvar)
{
        list_t *node = (*jinfo).env;
        size_t i = 0;
        char *j;

        if (!node || !jvar)
                return (0);

        while (node)
        {
                j = jstarts_with((*node).jstr, jvar);
                if (j && *j == '=')
                {
                        (*jinfo).env_changed = jdelete_node_at_ind(&((*jinfo).env), i);
                        i = 0;
                        node = (*jinfo).env;
                        continue;
                }
                node = (*node).next;
                i++;
        }
        return ((*jinfo).env_changed);
}
