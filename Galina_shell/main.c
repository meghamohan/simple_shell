#include "shell.h"

/*
 *
 */

int main(void)
{
	size_t bufsize = 0;
	char *input;
	char **command;

	checkmode();
/* start infinite loop with prompt */
	while(1)
	{
		command = malloc(sizeof(char) * 100);
		if (command == NULL)
		{
			perror("Can't malloc space");
			exit(1);
		}
		else if (getline(&input, &bufsize, stdin) == EOF)
		{
			perror("Error: end of file");
			writePrompt();
			free(input);
			break;
		}
		else if (_strcmp(input, "\n") == 0)
		{
			writePrompt();
			break;
		}
		else
		{
			tokenizer(input,command);
			execute(command);
			writePrompt();
		}
		/*free(input);*/
		free(command);
	}
	free(input);
	free(command);
	return(0);
}
