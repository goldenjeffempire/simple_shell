#include "joshell.h"

/**
 * find_cmd - this function finds a command in PATH
 * @jinfo: the parameter and returns jinfo struct
 * Return: void
 */
void find_cmd(jinfo_a *jinfo)
{
        char *path = NULL;
        int j, l;

        (*jinfo).path = (*jinfo).argv[0];
        if ((*jinfo).linecount_flag == 1)
        {
                (*jinfo).line_count++;
                (*jinfo).linecount_flag = 0;
        }
        for (j = 0, l = 0; (*jinfo).arg[j]; j++)
                if (!joelim((*jinfo).arg[j], " \t\n"))
                        l++;
        if (!l)
                return;

        path = find_jpath(jinfo, _juseenv(jinfo, "PATH="), (*jinfo).argv[0]);
        if (path)
        {
                (*jinfo).path = path;
                fork_cmd(jinfo);
        }
        else
        {
                if ((interact(jinfo) || _juseenv(jinfo, "PATH=")
                        || (*jinfo).argv[0][0] == '/') && jcmd(jinfo, (*jinfo).argv[0]))
                        fork_cmd(jinfo);
                else if (*((*jinfo).arg) != '\n')
                {
                        (*jinfo).status = 127;
                        print_error(jinfo, "not found\n");
                }
        }
}
