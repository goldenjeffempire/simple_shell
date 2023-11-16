#include "joshell.h"

/**
 * _jerratoi - function that converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers are in string
 */
int _jerratoi(char *s)
{
        int a = 0;
        unsigned long int result = 0;

        if (*s == '+')
                s++;
        for (a = 0;  s[a] != '\0'; a++)
        {
                if (s[a] >= '0' && s[a] <= '9')
                {
                        result *= 10;
                        result += (s[a] - '0');
                        if (result > INT_MAX)
                                return (-1);
                }
                else
                        return (-1);
        }
        return (result);
}
