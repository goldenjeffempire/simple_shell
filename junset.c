#include "joshell.h"

/**
 * _junsetenv - Remove an environment variable
 * @jinfo: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _junsetenv(jinfo_a *jinfo)
{
	int j;

	if ((*jinfo).argc == 1)
	{
		_puts("Too few arguements.\n");
		return (1);
	}
	for (j = 1; j <= (*jinfo).argc; j++)
		j_unsetenv(jinfo, (*jinfo).argv[j]);

	return (0);
}
