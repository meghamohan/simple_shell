#include "shell.h"
#include <string.h>

/**
* excute - executes the parent and child process
* @tokens : tokenized array of commands
* Return - nothing
*/
void excute(char **tokens)
{
	pid_t pid;
	int status;
	char *envp;

	pid = fork();
	if (pid == -1)
	{
 		printf("Forking Error\n");
	//	exit(NULL);
	}
	if (pid == 0)
	{
		envp = NULL;
		if (execve(tokens[0], tokens, NULL) == -1)
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
	int buffsize = BUFFSIZE, i = 0;
	char **tokens = malloc(64 * sizeof(char *)), *token;

	if (!tokens)
		printf("not possible to allocate memory\n");
	token = strtok(cmd," \t\n");
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
void printPrompt()
{
	char *cmd, **tokenizedArray;
	int readStatus = 0;
	size_t n;

	printf("myShell$ ");
	while(readStatus = getline(&cmd,&n, stdin )!= EOF)
	{
		if (!readStatus)
		{
			printf("Error in reading the command\n");
			break;
		}
		tokenizedArray = parseCommand(cmd);
		excute(tokenizedArray);
		printf("myShell$ ");
	}

}
/**
* main - the main entry point of shell program
* return - always 0
*/
int main( )
{
	printPrompt();
	return (0);
}
