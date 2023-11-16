#include "joshell.h"

/**
 * _strcmp - this function compares two strings
 * @j1: first string to compare
 * @j2: second string to compare
 * Return: j1 and j2
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

/**
 * _strcat - function that concatenates two strings
 * @dest: string to append
 * @src: string to add
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
        int j = 0, t = 0;

        while (dest[j] != '\0')
        {
                j++;
        }

        while (src[t] != '\0')
        {
                dest[j] = src[t];
                j++;
                t++;
        }
        dest[j] = '\0';
        return (dest);
}

/**
 * *_strchr - function locates a character in a string
 * @s: string to search
 * @e: char to find
 * Return: NULL
 */

char *_strchr(char *s, char e)
{
                int b;

                while (1)
                {
                        b = *s++;
                        if (b == e)
                        {
                                return (s - 1);
                        }
                        if (b == '\0')
                        {
                                return (NULL);
                        }
                }
}

/**
 * *_strcpy - function copies the string
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
        int ten = 0, j = 0;

        while (src[ten] != '\0')
        {
                ten++;
        }

        while (j < ten)
        {
                dest[j] = src[j];
                j++;
        }
        dest[j] = '\0';

        return (dest);
}

/**
 * _strlen - function that returns the length of a string
 * @j: string to evaluate
 * Return: length of the string
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
