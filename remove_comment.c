#include "joshell.h"

/**
 * remove_comments - function replaces character '#' with '\0'
 * @buf: points to address of the string to modify
 * Return: Always 0.
 */
void remove_comments(char *buf)
{
        int a;

        for (a = 0; buf[a] != '\0'; a++)
                if (buf[a] == '#' && (!a || buf[a - 1] == ' '))
                {
                        buf[a] = '\0';
                        break;
                }
}
