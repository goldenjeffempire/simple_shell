#include "joshell.h"

/**
 * cmd - function that determines if the file is an executable command
 * @jinfo: the jinfo struct
 * @path: path pointer
 * Return: 1 if success and else 0
 */
int cmd(jinfo_a *jinfo, char *path)
{
        struct stat st;

        (void)jinfo;
        if (!path || stat(path, &st))
                return (0);

        if (st.st_mode & S_IFREG)
        {
                return (1);
        }
        return (0);
}
