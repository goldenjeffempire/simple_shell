#include "joshell.h"

/**
 * _jputchar: this function writes the character 'c' to stderr
 * @c: character to be printed
 * On error, -1 is returned, and error is set appropriately.
 * Return: 1 if successful
 */
int _jputchar(char c)
{
        static int a;
        static char buf[JOBUF_SIZE];

        if (c == JOBUF_JOLUSH || a >= JOBUF_SIZE)
        {
                write(2, buf, a);
                a = 0;
        }
        if (c != JOBUF_JOLUSH)
                buf[a++] = c;
        return (1);
}
