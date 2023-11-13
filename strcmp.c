#include "joshell.h"

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int _strcmp(char *j1, char *j2)
{
	while (*j1 == *j2)
	{
		if (*j1 == '\0')
		{
			return (0);
		}
		j1++;
		j2++;
	}
	return (*j1 - *j2);
}
