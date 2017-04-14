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
* print_env_list - prints the environ list
* @h: environ list to be printed
* Return - returns the number of variables printed
*/
size_t print_env_list(env *h)
{

	unsigned int n;

	n = 0;
	if (!h)
		printf("error\n");
	while (h != NULL)
	{
		n++;
		h = (h)->next;
	}

	return (n);

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
	while(temp != NULL)
	{
		if (strcmp(temp->key, name) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

/**
* pathParse - parses each directory from the 
* @head: environ list
* @env_var: environ variable to be added
* Return - returns the endnode
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
* addEnv - adds an environ variable to the environ list
* @head: environ list
* @env_var: environ variable to be added
* Return - returns the endnode
*/
int getExecutablePath(char *cmd)
{
	int result;
	
	result = access (cmd, F_OK); 
/* F_OK tests existence also (R_OK,W_OK,X_OK)
for readable, writeable, executable */
	if ( result == 0 )
		return (1);
	else
		return (0);
}

/*
void main()
{
	char **temp = NULL;
	env *head = NULL;
	size_t n;

	n = create_env_list(&head);
	n = print_env_list(head);
	char *t = _getenv(head, "PATH");	
	printf("this is path %s\n", t);
	temp = pathParse(head);
	int i = 0; char *tempStr1 = NULL, *tempStr2 = NULL;;
	printf("PRINTING ALL PATH DIRS\n");
	while (temp[i])
	{
		printf("%s\n",temp[i]);
		tempStr1 = str_concat(temp[i], "/");
		tempStr1 = str_concat(tempStr1, "ls");
		printf("%s\n",tempStr1);
		if (getExecutablePath(tempStr1))
			printf("doExcve\n");
		else
			printf("checkforbuiltins\n");
		i++;
	}
}
*/