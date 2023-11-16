#include "joshell.h"

/**
 * set_alias - function that sets alias to the string
 * @jinfo: parameter struct
 * @jstr: the pointing to string alias
 * Return: Always 0 if successful
 */
int set_alias(jinfo_a *jinfo, char *jstr)
{
        char *j;

        j = _strchr(jstr, '=');
        if (!j)
                return (1);
        if (!*++j)
                return (set_alias(jinfo, jstr));

        set_alias(jinfo, jstr);
        return (jadd_node_end(&((*jinfo).alias), jstr, 0) == NULL);
}

/**
 * print_alias - this function prints an alias string
 * @node: the pointer alias node
 * Return: Always 0 if successful else 1
 */
int print_alias(list_t *node)
{
        char *j = NULL, *a = NULL;

        if (node)
        {
                j = _strchr((*node).jstr, '=');
                for (a = (*node).jstr; a <= j; a++)
                        _putchar(*a);
                _putchar('\'');
                _puts(j + 1);
                _puts("'\n");
                return (0);
        }
        return (1);
}
