#include "joshell.h"

/**
 * read_buf - reads a buffer
 * @jinfo: parameter struct
 * @buf: buffer
 * @j: size
 *
 * Return: t
 */
ssize_t read_buf(jinfo_a *jinfo, char *buf, size_t *j)
{
	ssize_t t = 0;

	if (*j)
		return (0);
	t = read((*jinfo).readjo, buf, JOBUF_SIZE);
	if (t >= 0)
		*j = t;
	return (t);
}
