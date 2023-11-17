#include "joshell.h"

/**
 * joelim -this function checks if character is a delimeter
 * @d: parameter to check
 * @joselim: the delimeter string
 * Return: 1 if true, and else 0
 */
int joelim(char d, char *joselim)
{
        while (*joselim)
                if (*joselim++ == d)
                        return (1);
        return (0);
}
