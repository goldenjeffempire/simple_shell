#include "joshell.h"

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @jo: the filedescriptor to write to
 *
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
