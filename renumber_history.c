#include "joshell.h"

/**
 * renumber_history - renumbers the history linked list after changes
 * @jinfo: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
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
