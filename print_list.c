#include "joshell.h"

/**
 * _printlist - prints all elements of a list_t linked list
 * @hd: pointer to first node
 *
 * Return: size of list
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
