#include "joshell.h"

/**
 * j_unsetenv - Remove an environment variable
 * @jinfo: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @jvar: the string env var property
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
