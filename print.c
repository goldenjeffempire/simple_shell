#include "joshell.h"

/**
 * print_d - function prints decimal number (base 10)
 * @input: the input
 * @jo: the file descriptor to write to
 * Return: number of characters printed
 */
int print_d(int input, int jo)
{
        int (*__putchar)(char) = _putchar;
        int j, count = 0;
        unsigned int _abs_, current;

        if (jo == STDERR_FILENO)
                __putchar = _putchar;
        if (input < 0)
        {
                _abs_ = -input;
                __putchar('-');
                count++;
        }
        else
                _abs_ = input;
        current = _abs_;
        for (j = 1000000000; j > 1; j /= 10)
        {
                if (_abs_ / j)
                {
                        __putchar('0' + current / j);
                        count++;
                }
                current %= j;
        }
        __putchar('0' + current);
        count++;

        return (count);
}

/**
 * print_error - function prints an error message
 * @jinfo: the parameter return jinfo struct
 * @jstr: string containing specified error type
 * Return: 0 if no numbers in string, else -1
 */
void print_error(jinfo_a *jinfo, char *jstr)
{
        _puts((*jinfo).fname);
        _puts(": ");
        print_d((*jinfo).line_count, STDERR_FILENO);
        _puts(": ");
        _puts((*jinfo).argv[0]);
        _puts(": ");
        _puts(jstr);
}

/**
 * _printlist - this function prints all elements of a list_t linked-list
 * @hd: pointer to first node
 * Return: j.
 */
size_t _printlist(const list_t *hd)
{
        size_t j = 0;

        while (hd)
        {
                _puts(convert_number((*hd).num, 10, 0));
                _putchar(':');
                _putchar(' ');
                _puts((*hd).jstr ? (*hd).jstr : "(nil)");
                _puts("\n");
                hd = (*hd).next;
                j++;
        }
        return (j);
}

/**
 * print_list_str -this prints only the fstr element of a list_t linked list
 * @j: pointer to first node
 * Return: a.
 */
size_t print_list_str(const list_t *j)
{
        size_t a = 0;

        while (j)
        {
                _puts((*j).jstr ? (*j).jstr : "(nil)");
                _puts("\n");
                j = (*j).next;
                a++;
        }
        return (a);
}
