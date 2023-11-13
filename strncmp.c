#include "joshell.h"

/**
 * _strncmp - compares two strings up to a specified number of characters
 * @j1: first string to compare
 * @j2: second string to compare
 * @o: maximum number of characters to compare
 *
 * Return: less than 0 if j1 is less than j2, 0 if they're equal,
 * more than 0 if j1 is greater than j2
 */
int _strncmp(const char *j1, const char *j2, size_t o)
{
    while (o && *j1 && (*j1 == *j2))
    {
        j1++;
        j2++;
        o--;
    }

    return (o ? *j1 - *j2 : 0);
}
