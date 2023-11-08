#include "joshell.h"

/**
 * _jputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
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
