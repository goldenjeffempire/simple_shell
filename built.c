#include "joshell.h"

/**
 * _history - this funtion displays the history list, one command by line, 
 * preceded with line numbers, starting at 0.
 * @jinfo: this structure contains potential arguments
 * that is used to maintain constant function prototype.
 * Return: 0
 */
int _history(jinfo_a *jinfo)
{
        _jprintlist((*jinfo).history);
        return (0);
}

/**
 * unset_alias - function that sets alias to a string
 * @jinfo: parameter struct pointer
 * @jstr: this  points to string alias
 * Return: Always 0 if successful, else 1
 */
int unset_alias(jinfo_a *jinfo, char *jstr)
{
        char *j, c;
        int jret;

        j = _strchr(jstr, '=');
        if (!j)
                return (1);
        c = *j;
        *j = 0;
        jret = jdelete_node_at_ind(&((*jinfo).alias),
                use_node_ind((*jinfo).alias, jnode_starts_with((*jinfo).alias, jstr, -1)));
        *j = c;
        return (jret);
}
