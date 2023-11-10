#include "joshell.h"

/**
 * get_env - returns the string array copy of our environ
 * @jinfo: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_env(jinfo_a *jinfo)
{
	if (!(*jinfo).environ || (*jinfo).env_changed)
	{
		(*jinfo).environ = jlist_to_strings((*jinfo).env);
		(*jinfo).env_changed = 0;
	}

	return ((*jinfo).environ);
}
