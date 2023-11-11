#include "joshell.h"

/**
 * list_ten - determines length of linked list
 * @hd: pointer to first node
 *
 * Return: size of list
 */
size_t list_ten(const list_t *hd)
{
	size_t j = 0;

	while (hd)
	{
		hd = (*hd).next;
		j++;
	}
	return (j);
}
