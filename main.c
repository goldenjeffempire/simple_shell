#include "joshell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
void main(int ac, char **av)
{
	jinfo_a jinfo[] = { INFO_INIT };
	int jo = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (jo)
		: "r" (jo));

	if (ac == 2)
	{
		jo = open(av[1], O_RDONLY);
		if (jo == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_jputs(av[0]);
				_jputs(": 0: Can't open ");
				_jputs(av[1]);
				_jputchar('\n');
				_jputchar(JOBUF_JOLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		(*jinfo).readjo = jo;
	}
	jpop_env_list(jinfo);
	read_jhistory(jinfo);
	shell(jinfo, av);
	return (EXIT_SUCCESS);
}
