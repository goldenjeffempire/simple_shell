#include "shell.h"

/**
 * main - function prototype
 * @argc: argument count of passed argument
 * @argv: argument vector
 * Return: 0
 */
int main(__attribute((unused))int argc, char **argv)
{
	int status_code = 0, j = 0, command_number = 1;
	char *delimiter = " \t\n\r", *command = NULL;
	char **args = NULL;
	size_t length = 0;
	ssize_t s = 0;
	struct stat sb;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		s = getline(&command, &length, stdin);
		if (s == -1)
		{
			free(command);
			exit(status_code);
		}
		args = _tokenizer(command, delimiter);
		_should_exit(command, status_code, args);
		if (_should_env(command, args) == 0)
			continue;
		if (args != NULL && args[0] != NULL)
		{
			if (stat(args[0], &sb) == -1)
				status_code = _perror(argv[0], command_number, args[0]);
			else
				status_code = _fork(args[0], args);
		}
		else if (args == NULL)
			status_code = _perror(argv[0], command_number, command);
		if (args != NULL)
		{
			for (j = 0; args[j] != NULL; j++)
				free(args[j]);
			free(args);
		}
		command_number++;
	}
	return (0);
}
