#include "joshell.h"
/**
 * pop_env_list - funtion that populates env linked-list
 * @jinfo: this is pointing to structure containing potential arguments
 *  and used to maintain constant function prototype.
 * Return: Always 0
 */
int pop_env_list(jinfo_a *jinfo)
{
        list_t *node = NULL;
        size_t j;

        for (j = 0; environ[j]; j++)
                jadd_node_end(&node, environ[j], 0);
        (*jinfo).env = node;
        return (0);
}
