#include "joshell.h"

/**
 * cmd - determines if a file is an executable command
 * @jinfo: the jinfo struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int cmd(jinfo_a *jinfo, char *path)
{
	struct stat st;

	(void)jinfo;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
