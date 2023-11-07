#include "joshell.h"

/**
 * jchain - test if current char in buffer is a chain delimeter
 * @jinfo: the parameter struct
 * @jobuf: the char buffer
 * @j: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int jchain(jinfo_a *jinfo, char *buf, size_t *f)
{
	size_t j = *f;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		(*jinfo).cmd_buf_type = JOMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		(*jinfo).cmd_buf_type = JOMD_AND;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0; /* replace semicolon with null */
		(*jinfo).cmd_buf_type = JOMD_CHAIN;
	}
	else
		return (0);
	*f = j;
	return (1);
}
