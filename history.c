#include "joshell.h"

/**
 * use_history_file - this function uses the history file
 * @jinfo: parameter struct
 * Return: allocated string
 */

char *use_history_file(jinfo_a *jinfo)
{
        char *buf, *jodir;

        jodir = _juseenv(jinfo, "HOME=");
        if (!jodir)
                return (NULL);
        buf = malloc(sizeof(char) * (_strlen(jodir) + _strlen(JOHIST_FILE) + 2));
        if (!buf)
                return (NULL);
        buf[0] = 0;
        _strcpy(buf, jodir);
        _strcat(buf, "/");
        _strcat(buf, JOHIST_FILE);
        return (buf);
}
