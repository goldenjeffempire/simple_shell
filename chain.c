#include "joshell.h"

/**
 * replace_vars - this function replaces vars in the tokenized string
 * @jinfo: the parameter struct pointer
 * Return: 1 if replaced, else 0
 */
int replace_vars(jinfo_a *jinfo)
{
        int i = 0;
        list_t *node;

        for (i = 0; (*jinfo).argv[i]; i++)
        {
                if ((*jinfo).argv[i][0] != '$' || !(*jinfo).argv[i][1])
                        continue;

                if (!_strcmp((*jinfo).argv[i], "$?"))
                {
                        replace_string(&((*jinfo).argv[i]),
                                _strdup(convert_number((*jinfo).status, 10, 0)));
                        continue;
                }
                if (!_strcmp((*jinfo).argv[i], "$$"))
                {
                        replace_string(&((*jinfo).argv[i]),
                                _strdup(convert_number(getpid(), 10, 0)));
                        continue;
                }
                node = jnode_starts_with((*jinfo).env, &(*jinfo).argv[i][1], '=');
                if (node)
                {
                        replace_string(&((*jinfo).argv[i]),
                                _strdup(_strchr((*node).jstr, '=') + 1));
                        continue;
                }
                replace_string(&(*jinfo).argv[i], _strdup(""));

        }
        return (0);
}

/**
 * replace_string - replaces string
 * @old: double pointer to address of old string
 * @new: pointer new string
 * Return: 1 if replaced, else 0
 */
int replace_string(char **old, char *new)
{
        free(*old);
        *old = new;
        return (1);
}
