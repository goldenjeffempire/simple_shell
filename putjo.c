#include "joshell.h"

/**
 * _jputjo - writes the character c to given fd
 * @c: The character to print
 * @jo: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
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
