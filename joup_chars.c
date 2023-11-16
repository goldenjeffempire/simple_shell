#include "joshell.h"

/**
 * joup_chars - function that duplicates characters
 * @pathjstr: the PATH string pointer
 * @jstart: starting index parameter
 * @jstop: stopping index parameter
 * Return: buf
 */
char *joup_chars(char *pathjstr, int jstart, int jstop)
{
        static char buf[1024];
        int s = 0, y = 0;

        for (y = 0, s = jstart; s < jstop; s++)
                if (pathjstr[s] != ':')
                        buf[y++] = pathjstr[s];
        buf[y] = 0;
        return (buf);
}
