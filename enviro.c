#include "joshell.h"

/**
 * _env - funtion that prints the current environment
 * @jinfo: this pointing to structure containing potential arguments
 *that is used to maintain constant function prototype.
 * Return: Always 0
 */
int _env(jinfo_a *jinfo)
{
        jprint_list_str((*jinfo).env);
        return (0);
}
