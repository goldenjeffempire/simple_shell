#include "joshell.h"

/**
 * _strncat - this function concatenates n bytes from a string to another
 * @dest: string destination
 * @src: string source
 * @o: number of bytes of str to concatenate
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

/**
 * _strncmp - this compares two strings up to a specified number of characters
 * @j1: first string to be compared
 * @j2: second string to be compared
 * @o: maximum number of characters to compare
 * Return: less than 0 if j1 is less than j2
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

/**
 * _strncpy -function that copies a string
 * @dest:string destination
 * @src: string source
 * @o: number of bytes to copy
 * Return: pointer to the resulting string dest
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
