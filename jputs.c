#include "joshell.h"

/**
 *_jputs - function that prints an input string
 * @jstr: the string to be printed
 * Return: Nothing
 */
void _jputs(char *jstr)
{
        int a = 0;

        if (!jstr)
                return;
        while (jstr[a] != '\0')
        {
                _jputchar(jstr[a]);
                a++;
        }
}
