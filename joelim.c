#include "joshell.h"

/**
 * joelim -this function checks if character is a delimeter
 * @d: parameter to check
 * @josdelim: the delimeter string
 * Return: 1 if true, and else 0
 */
int jodelim(char d, char *josdelim)
{
        while (*josdelim)
                if (*josdelim++ == d)
                        return (1);
        return (0);
}
