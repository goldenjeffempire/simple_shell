#include "joshell.h"

/**
 * fork_cmd - forks a an exec thread to run cmd
 * @jinfo: the parameter & return finfo struct
 *
 * Return: void
 */
void fork_cmd(jinfo_a *jinfo)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve((*jinfo).path, (*jinfo).argv, juse_env(jinfo)) == -1)
		{
			free_jinfo(jinfo, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&((*jinfo).status));
		if (WIFEXITED((*jinfo).status))
		{
			(*jinfo).status = WEXITSTATUS((*jinfo).status);
			if ((*jinfo).status == 126)
				print_error(jinfo, "Permission denied\n");
		}
	}
}
