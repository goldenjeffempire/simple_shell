#include "joshell.h"

/**
 * _strncat - concatenates n bytes from a string to another
 * @dest: destination string
 * @src: source string
 * @o: number of bytes of str to concatenate
 *
 * Return: a pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int o)
{
	int j = 0, y = 0;

	while (dest[j] != '\0')
		j++;

	while (src[y] != '\0' && y < o)
	{
		dest[j] = src[y];
		j++;
		y++;
	}

	dest[j] = '\0';

	return (dest);
}
