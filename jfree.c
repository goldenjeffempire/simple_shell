#include "joshell.h"

/**
 * jfree - jfrees a string of strings
 * @pp: string of strings
 */
void jfree(char *p)
{
	char *i = p;

	if (!p)
		return;
	while (*p)
		jfree(p++);
	jfree(i);
}
