#include "shell.h"

/*
 * file to create child process, execute env if found
 */

void execute(char **command)
{
	pid_t child;
	int status, execute;
	char *token_path;

	child = fork();
	if (child < 0)
	{
		perror("Error creating child process");
		_exit(1);
	}
	if (child == 0)
	{
		if (_strcmp(command[0], "exit") == 0)
			exit(0);
		if(_strcmp(command[0], "env") == 0)
		{
			printenviron();
			_exit(0);
		}
		token_path = path_split(command[0]);

		if (statcheck(token_path) == 0)
		{
			execute = execve(token_path, command, environ);
			if(execute < 0)
			{
				write(STDOUT_FILENO, command[0], _strlen(command[0]));
				command_error();
				_exit(0);
			}
		}
		else if (execve(command[0], command, environ) < 0)
		{
			write(STDOUT_FILENO, command[0], _strlen(command[0]));
			command_error();
			_exit(0);
		}
		free(token_path);
		free(command);
	}
	else
		wait(&status);
}
