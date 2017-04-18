#include "shell.h"
#include <string.h>
#define PROMPT "myShell$ "

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
		perror("Forking Error\n");
	}
	if (pid == 0)
	{
		if ((execve(cmdPath, tokens, environ)) == -1)
		{
		  perror("No such file or directory\n");
		}
	}
	else
		waitpid(-1, &status, 0);
}


/**
* parseCommand - tokenizes the commandline that is read from
* the terminal
* @cmd : the command that is read using readline command
* Return: returns a string array of the tokenized strings
*/
char **parseCommand(char *cmd, char **tokens)
{
	int i = 0;
	char *token;

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
	free(token);
	return (tokens);
}

/**
* printPrompt - prints prompt, gets a line containing command
* parses it and executes it by calling system call execve
*/

void printPrompt(env *head, int InteracFlag)
{
	char **temp = NULL;
	char *cmd = NULL, **tokenizedArray, *tempStr1 = NULL;
	int i = 0, readStatus = 0;
	size_t n;

	tokenizedArray = malloc(32 * sizeof(char *));
	temp = pathParse(head);
	while ((readStatus = getline(&cmd, &n, stdin)) != EOF)
	{
		if (!readStatus)
		{
			perror("Error in reading the command\n");
			exit(1);
		}
		if(_strcmp(cmd, "exit") == 0)
			break;
		if (_strcmp(cmd, "\n") == 0)
		{
			writeIt();
			continue;
		}
		parseCommand(cmd, tokenizedArray);
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
				{
				      write(STDOUT_FILENO, "Command does not exist\n", 24);
				      break;
				}
			}
		/*	if (getMyBuiltins(head, tokenizedArray))
				break;*/
			i++;
		}
		i = 0;
		if (InteracFlag)
			writeIt();
	}
	freeStringArray(temp);
}
/**
* main - the main entry point of shell program
* Return: always 0
*/
int main(void)
{
	env *head = NULL;
	struct stat interac;
	int InteracFlag = 0, n1;
	char *t;
	fstat(STDIN_FILENO, &interac);

	if (S_ISCHR(interac.st_mode))
	{
		writeIt();
		InteracFlag = 1;
	}
	n1 = create_env_list(&head);
	if (!n1)
		perror("env variables not created\n");
	t = _getenv(head, "PATH");
	if (!t)
		perror("No such file or directory\n");

	printPrompt(head, InteracFlag);
	freeEnvironList(head);
	return (0);
}
