#include "joshell.h"

/**
 * *_memset - fills memory with a constant byte
 * @t: memory area to be filled
 * @c: char to copy
 * @o: number of times to copy c
 *
 * Return: pointer to the memory area t
 */
char *_memset(char *t, char c, unsigned int o)
{
	unsigned int mem = 0;

	while (mem < o)
	{
		t[mem] = c;
		mem++;
	}

	return (t);
}
