#include "joshell.h"

/**
 * _jputjo -function writes the character c
 * @c: parameter character to print
 * @jo: The filedescriptor to write to
 * Return: On success 1.
 * On error, -1 is returned.
 */
int _jputjo(char c, int jo)
{
        static int j;
        static char buf[JOBUF_SIZE];

        if (c == JOBUF_JOLUSH || j >= JOBUF_SIZE)
        {
                write(jo, buf, j);
                j = 0;
        }
        if (c != JOBUF_JOLUSH)
                buf[j++] = c;
        return (1);
}

/**
 *_jputjo -function prints an input string
 * @jstr: the string to be printed
 * @jo: the file descriptor to write to
 * Return: a.
 */
int _jputsjo(char *str, int jo)
{
        int a = 0;

        if (!str)
                return (0);
        while (*str)
        {
                a += _jputjo(*str++, jo);
        }
        return (a);
}
