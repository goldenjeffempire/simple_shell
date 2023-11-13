#include "joshell.h"

/**
 * _strlen - returns the length of a string
 * @j: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *j)
{
	int strcount = 0;

	while (j[strcount] != '\0')
	{
		strcount++;
	}

	return (strcount);
}
