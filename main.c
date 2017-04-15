#include "shell.h"
#include <string.h>

/**
* excute - executes the parent and child process
* @tokens : tokenized array of commands
* @cmdPath : command with the complete path
* Return - nothing
*/
void excute(char **tokens, char *cmdPath)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		printf("Forking Error\n");
	}
	if (pid == 0)
	{
		if (execve (cmdPath, tokens, NULL) == -1)
		{
		  printf("No such file or directory\n");
		}
	}
	else
		waitpid(pid, &status, 0);
}


/**
* parseCommand - tokenizes the commandline that is read from
* the terminal
* @cmd : the command that is read using readline command
* Return - returns a string array of the tokenized strings
*/
char **parseCommand(char *cmd)
{
	int i = 0;
	char **tokens = malloc(32 * sizeof(char *)), *token;

	if (!tokens)
	{
		perror("not possible to allocate memory\n");
		return (NULL);
	}
	token = strtok(cmd, " \t\n");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
* printPrompt - prints prompt, gets a line containing command
* parses it and executes it by calling system call execve
*/

void printPrompt(void)
{
	char **temp = NULL;
	env *head = NULL;
	struct stat interac;
	char *t, *cmd, **tokenizedArray;
	int readStatus = 0, NonInteracFlag;
	size_t n, n1;

	int i = 0; char *tempStr1 = NULL;
	if (fstat (STDIN_FILENO, &interac) == -1)
	{
		perror("fstat error:\n");
		exit(EXIT_FAILURE);
	}
	switch (interac.st_mode & S_IFMT)
	{
	case S_IFIFO:
		NonInteracFlag = 1;
		break;
	}
	if (NonInteracFlag == 0)
		printf("myShell$ ");

	n1 = create_env_list(&head);
	if (!n1)
		perror("env variables not created\n");
	t = _getenv(head, "PATH");
	if (!t)
		perror("cannot retrieve path directories\n");

	temp = pathParse(head);
	while ((readStatus = getline(&cmd, &n, stdin)) != EOF)
	{
		if (!readStatus)
		{
			perror("Error in reading the command\n");
			exit(1);
		}
		tokenizedArray = parseCommand(cmd);
		while (temp[i])
		{
			if (getExecutablePath(tokenizedArray[0]))
			{
				excute(tokenizedArray, tokenizedArray[0]);
				break;
			}
			else
			{
				tempStr1 = str_concat(temp[i], "/");
				tempStr1 = str_concat(tempStr1, tokenizedArray[0]);
				if (getExecutablePath(tempStr1))
				{
					excute(tokenizedArray, tempStr1);
					break;
				}
				else
					printf("checkforbuiltins\n");
			}
			i++;
		}
		i = 0;
		if (NonInteracFlag == 0)
			printf("myShell$ ");
	}
	free(cmd);
	free(temp);
	free(head);
}
/**
* main - the main entry point of shell program
* return - always 0
*/
int main(void)
{
	printPrompt();
	return (0);
}
