#include "joshell.h"

/**
 * check_fchain - checks we should continue chaining based on last status
 * @finfo: the parameter struct
 * @buf: the char buffer
 * @f: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void check_chain(jinfo_a *jinfo, char *buf, size_t *f, size_t i, size_t len)
{
	size_t j = *f;

	if ((*jinfo).cmd_buf_type == JOMD_AND)
	{
		if ((*jinfo).status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if ((*jinfo).cmd_buf_type == JOMD_OR)
	{
		if (!(*jinfo).status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*f = j;
}
