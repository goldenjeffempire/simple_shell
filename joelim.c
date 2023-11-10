#include "joshell.h"

/**
 * joelim - checks if character is a delimeter
 * @d: the char to check
 * @josdelim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int jodelim(char d, char *josdelim)
{
	while (*josdelim)
		if (*josdelim++ == d)
			return (1);
	return (0);
}
