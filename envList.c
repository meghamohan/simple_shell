#include "shell.h"

env * addEnv(env **head, char *env_var)
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

size_t print_env_list(env *h)
{

	unsigned int n;

	n = 0;
	if (!h)
		printf("error\n");
	while (h != NULL)
	{
		printf("key: %s, value: %s\n",h->key,h->value);
		n++;
		h = (h)->next;
	}

	return (n);

}

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

	tokenizedPath = strtok(pathValue, ":");
	while (tokenizedPath != NULL)
	{
		pathList[i] = strdup(tokenizedPath);
		i++;
		tokenizedPath = strtok(NULL, ":");
	}
	pathList[i] = NULL;
	return (pathList);
}

void getExecutablePath(char *cmd)
{
	int result;
	const char *filename = "/tmp/myfile";
	result = access (cmd, F_OK); // F_OK tests existence also (R_OK,W_OK,X_OK).
                                  //            for readable, writeable, executable
	if ( result == 0 )
	{
		printf("%s exists!!\n",cmd);
	}
	else
	{
   	printf("ERROR: %s doesn't exist!\n",cmd);
	}
}
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
		
		getExecutablePath(tempStr1);
		i++;
	}
}

