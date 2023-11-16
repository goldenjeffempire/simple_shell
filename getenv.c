#include "joshell.h"

/**
 * get_env - function that returns the string array copy of our environ
 * @jinfo: this is pointer to structure containing potential argument
 *  and used to maintain constant function prototype.
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
