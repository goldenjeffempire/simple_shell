#include "joshell.h"

/**
 * _strncpy - copies a string
 * @dest: destination string
 * @src: source string
 * @o: number of bytes to copy
 *
 * Return: pointer to the resulting string
 */
char *_strncpy(char *dest, char *src, int o)
{
	int j = 0;

	while (src[j] != '\0' && j < o)
	{
		dest[j] = src[j];
		j++;
	}

	while (j < o)
	{
		dest[j] = '\0';
		j++;
	}

	return (dest);
}
