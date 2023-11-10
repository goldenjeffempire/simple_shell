#include "joshell.h"

/**
 * write_history - creates a file, or appends to an existing file
 * @jinfo: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int write_jhistory(jinfo_a *jinfo)
{
	ssize_t jo;
	char *filename = use_jhistory_file(jinfo);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	jo = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	jfree(filename);
	if (jo == -1)
		return (-1);
	for (node = (*jinfo).history; node; node = (*node).next)
	{
		_jputsjo((*node).jstr, jo);
		_jputjo('\n', jo);
	}
	_jputjo(JOBUF_JOLUSH, jo);
	close(jo);
	return (1);
}
