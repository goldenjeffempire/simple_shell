#include "joshell.h"

/** * j_setenv: initializes a new environment variable or modify an existing one
 * @jinfo: this points to structure containing potential arguments * and it is used to maintain constant function prototype.
 *  Return: Always 0
 */
int j_setenv(jinfo_a *jinfo)
{
        if ((*jinfo).argc != 3)
        {
                _puts("Incorrect number of arguements\n");
                return (1);
        }
        if (_jsetenv(jinfo, (*jinfo).argv[1], (*jinfo).argv[2]))
                return (0);
        return (1);
}

/**
 * _setenv - this function initializes a new environment variable,
 *  or modify an existing one
 * @jinfo: this points to structure containing potential arguments.
 *  used to maintain constant function prototype.
 * @jvar: the string env var property
 * @jvalue: the string env var value
 *  Return: Always 0
 */
int _setenv(jinfo_a *jinfo, char *jvar, char *jvalue)
{
        char *buf = NULL;
        list_t *node;
        char *j;

        if (!jvar || !jvalue)
                return (0);

        buf = malloc(_strlen(jvar) + _strlen(jvalue) + 2);
        if (!buf)
                return (1);
        _strcpy(buf, jvar);
        _strcat(buf, "=");
        _strcat(buf, jvalue);
        node = (*jinfo).env;
        while (node)
        {
                j = jstarts_with((*node).jstr, jvar);
                if (j && *j == '=')
                {
                        jfree((*node).jstr);
                        (*node).jstr = buf;
                        (*jinfo).env_changed = 1;
                        return (0);
                }
                node = (*node).next;
        }
        jadd_node_end(&((*jinfo).env), buf, 0);
        jfree(buf);
        (*jinfo).env_changed = 1;
        return (0);
}
