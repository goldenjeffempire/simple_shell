#include "joshell.h"

/**
 * input_buf - buffers chained commands
 * @jinfo: parameter struct
 * @buf: address of buffer
 * @ten: address of ten var
 *
 * Return: bytes read
 */
ssize_t input_buf(jinfo_a *jinfo, char **buf, size_t *ten)
{
	ssize_t t = 0;
	size_t ten_p = 0;

	if (!*ten) /* if buffer is left with nothing, fill it */
	{
		jfree(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_FUSE
		 = useline(buf, &ten_p, stdin);
#else
		t = _juseline(jinfo, buf, &ten_p);
#endif
		if (t > 0)
		{
			if ((*buf)[t - 1] == '\n')
			{
				(*buf)[t - 1] = '\0'; /* no trailing newline */
				t--;
			}
			(*jinfo).linecount_flag = 1;
			remove_comments(*buf);
			build_jhistory_list(jinfo, *buf, (*jinfo).histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*ten = t;
				(*jinfo).cmd_buf = buf;
			}
		}
	}
	return (t);
}
