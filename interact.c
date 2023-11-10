#include "joshell.h"

/**
 * interact - returns true if shell is interact mode
 * @jinfo: struct address
 *
 * Return: 1 if interact mode, 0 otherwise
 */
int interact(jinfo_a *jinfo)
{
	return ((*jinfo).readjo <= 2);
}
