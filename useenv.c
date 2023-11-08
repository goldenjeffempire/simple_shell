#include "joshell.h"

/**
 * _useenv - gets the value of an environ variable
 * @jinfo: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
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
