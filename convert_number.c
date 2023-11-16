#include "joshell.h"

/**
 * convert_number - function that serves as a converter
 * @num: number parameter
 * @base: base parameter
 * @jlags: argument jlags
 * Return: string
 */
char *convert_number(long int num, int base, int jlags)
{
        static char *array;
        static char buffer[50];
        char sign = 0;
        char *ptr;
        unsigned long i = num;

        if (!(jlags & JOCONV_UNS) && num < 0)
        {
                i = -num;
                sign = '-';

        }
        array = jlags & JOCONV_LOW ? "0123456789abcdef" : "0123456789ABCDEF";
        ptr = &buffer[49];
        *ptr = '\0';

        do      {
                *--ptr = array[i % base];
                i /= base;
        } while (i != 0);

        if (sign)
                *--ptr = sign;
        return (ptr);
}
