#include "shell.h"
/**
* addEnv - adds an environ variable to the environ list
* @head: environ list
* @env_var: environ variable to be added
* Return - returns the endnode
*/
env *addEnv(env **head, char *env_var)
{
	env *endNode, *temp;

	if (env_var == NULL)
		return (NULL);
	endNode = (env *)malloc(sizeof(env));
	if (endNode == NULL)
		return (NULL);
	endNode->key = strtok(env_var, "=");
	endNode->value = strtok(NULL, "\0");
	endNode->next = NULL;
	if (*head == NULL)
	{
		*head = endNode;
		return (endNode);
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = endNode;

	return (endNode);
}

/**
* creat_env_list - creates a list of environ variables
* @head: list to where it has to be added
* Return - returns the number of environ variables
*/
int create_env_list(env **head)
{
	size_t i;

	i = 0;
	while (environ[i] != NULL)
	{
		addEnv(head, environ[i]);
		i++;
	}
	return (i);
}

/**
* _getenv - gets the value of a specific environ variable
* @envVars: environ list where the search has to be done
* @name: environ variable name
* Return - returns the value of environ
*/
char *_getenv(env *envVars, const char *name)
{
	env *temp;

	temp = envVars;
	while (temp != NULL)
	{
		if (strcmp(temp->key, name) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

/**
* pathParse - parses each directory from the PATH dir string
* @envList: env variable linked list
* Return - returns the string array of path dirs
*/
char **pathParse(env *envList)
{
	char **pathList;
	char *pathValue, *tokenizedPath;
	char *delim = ":";
	int i = 0;

	pathValue = _getenv(envList, "PATH");

	pathList = malloc(sizeof(char *) * 32);
	if (pathList == NULL)
		return (NULL);

	tokenizedPath = strtok(pathValue, delim);
	while (tokenizedPath != NULL)
	{
		pathList[i] = strdup(tokenizedPath);
		i++;
		tokenizedPath = strtok(NULL, delim);
	}
	pathList[i] = NULL;
	return (pathList);
}

/**
* getExecutablePath - checks if the given file is present
* in the attached path or not
* @cmd: command with the path
* Return - returns 1 if present 0 if not
*/
int getExecutablePath(char *cmd)
{
	int result;

	result = access(cmd, F_OK);
/**
* F_OK tests existence also (R_OK,W_OK,X_OK)
*for readable, writeable, executable
*/
	if (result == 0)
		return (1);
	else
		return (0);
}
