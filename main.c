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
		perror("Forking Error\n");
	}
	if (pid == 0)
	{
		if (execve(cmdPath, tokens, environ) == -1)
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
* @tokens : array to where the tokenized command has to be stored
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
* handleExecutableCommands - checks if the executable path is valid
* r not and executes if it is
* @tokenizedArray : tokenized array of commands
* @pathDirs : string array of path directories
* Return: returns if the command has been executed or not
*/
int handleExecutableCommands(char **tokenizedArray, char **pathDirs)
{
	char *cmdPath = NULL, *cmdPath1 = NULL;
	int i = 0;

	if (getExecutablePath(tokenizedArray[0]))
	{
	/*cmdPath = tokenizedArray[0];*/
		excute(tokenizedArray, tokenizedArray[0]);
		return (1);
	}
	else
	{
		while (pathDirs[i])
		{
			cmdPath1 = str_concat(pathDirs[i], "/");
			cmdPath = str_concat(cmdPath1, tokenizedArray[0]);
			if (getExecutablePath(cmdPath))
			{
				excute(tokenizedArray, cmdPath);
				free(cmdPath); free(cmdPath1);
				return (1);
			}
			i++;
			free(cmdPath); free(cmdPath1);
		}
	}
	return (0);

}



/**
* printPrompt - prints prompt, gets a line containing command
* parses it and executes it by calling system call execve
* @head : env linked list where environ variables are stored
* @InteracFlag : flag to chekc if the mode is interactive or not
* Return - nothing
*/

void printPrompt(env *head, int InteracFlag)
{
	char **pathDirs = NULL, *cmd = NULL, **tokenizedArray;
	int  handled, readStatus = 0; size_t n;

	pathDirs = pathParse(head);
	tokenizedArray = malloc(32 * sizeof(char *));
	n = 0;
	while ((readStatus = getline(&cmd, &n, stdin)) != EOF)
	{
		handled = 0;
		if (!readStatus)
		{
			perror("Error in reading the command\n");
			freeStringArray(tokenizedArray);
			exit(1);
		}
		if (_strcmp(cmd, "exit") == 0)
			break;
		if (_strcmp(cmd, "\n") == 0)
		{
			writePrompt();
			continue;
		}
		/* Parse command in to tokenized array.*/
		parseCommand(cmd, tokenizedArray);
		/* Handle builtins */
		handled = getMyBuiltins(&head, tokenizedArray);
		/* Handle full path commands. */
		if (!handled)
			handled = handleExecutableCommands(tokenizedArray, pathDirs);
		if (!handled)
		{
			perror("Command Not Found.\n");
		}
		/* Print prompt. */
		if (InteracFlag)
			writePrompt();
	}
	freeStringArray(pathDirs);
	free(cmd); free(tokenizedArray);
}


/**
* main - the main entry point of shell program
* Return: always 0
*/
int main(void)
{
	env *head = NULL;
	struct stat interac;
	int InteracFlag = 0, envLL;

	fstat(STDIN_FILENO, &interac);

	if (S_ISCHR(interac.st_mode))
	{
		writePrompt();
		InteracFlag = 1;
	}
	envLL = create_env_list(&head);
	if (!envLL)
		perror("env variables not created\n");
	printPrompt(head, InteracFlag);
	freeEnvironList(head);
	return (0);
}
