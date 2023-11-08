#include "joshell.h"

/**
 * _env - prints the current environment
 * @jinfo: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _env(jinfo_a *jinfo)
{
	jprint_list_str((*jinfo).env);
	return (0);
}
