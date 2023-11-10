#include "joshell.h"

/**
 * build_history_list - adds entry to a history linked list
 * @jinfo: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int build_history_list(jinfo_a *jinfo, char *buf, int linecount)
{
	list_t *node = NULL;

	if ((*jinfo).history)
		node = (*jinfo).history;
	jadd_node_end(&node, buf, linecount);

	if (!(*jinfo).history)
		(*jinfo).history = node;
	return (0);
}
