#include "joshell.h"

/**
 * interact - this returns true if shell is in the interact mode
 * @jinfo: struct address paramter
 * Return: 1 if mode interact, else 0
 */
int interact(jinfo_a *jinfo)
{
        return ((*jinfo).readjo <= 2);
}
