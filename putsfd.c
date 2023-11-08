#include "joshell.h"

/**
 *_jputsjo - prints an input string
 * @jstr: the string to be printed
 * @jo: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _jputsfjo(char *jstr, int jo)
{
	int a = 0;

	if (!jstr)
		return (0);
	while (*jstr)
	{
		a += _jputjo(*jstr++, jo);
	}
	return (a);
}
