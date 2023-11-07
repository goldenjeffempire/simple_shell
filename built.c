#include "joshell.h"

/**
 * _history - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @jinfo: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _history(jinfo_a *jinfo)
{
	_jprintlist((*jinfo).history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @jinfo: parameter struct
 * @jstr: the string alias
 *
 * Return: Always 0 on success, 1 on error
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
