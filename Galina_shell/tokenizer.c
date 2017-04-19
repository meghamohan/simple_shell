#include "shell.h"

/*
 *
 */

void tokenizer(char *input, char **command)
{
	int i = 0;

	command[i] = strtok(input," \t\n");
	while (command[i - 1] != NULL)
	{
		i++;
		command[i] = strtok(NULL, " \t\n");
	}
}
