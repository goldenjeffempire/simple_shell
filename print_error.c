#include "joshell.h"

/**
 * print_error - prints an error message
 * @jinfo: the parameter & return jinfo struct
 * @jstr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
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
