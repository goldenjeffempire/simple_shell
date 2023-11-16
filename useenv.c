#include "joshell.h"

/**
 * _useenv - function that gets the value of an environment variable * @jinfo: points to structure containing potential arguments. * Also used to maintain
 * @name: env var name
 * Return: NULL
 */
char *_useenv(jinfo_a *jinfo, const char *name)
{
        list_t *node = (*jinfo).env;
        char *j;

        while (node)
        {
                j = jstarts_with((*node).jstr, name);
                if (j && *j)
                        return (j);
                node = (*node).next;
        }
        return (NULL);
}
