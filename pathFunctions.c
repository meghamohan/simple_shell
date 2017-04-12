#include "shell.h"

/**
* _getenv - implementation of getenv shell function
* @name : the env var that needs to be listed
* Return - returns the value of env var as a string
*/
char *_getenv(const char *name)
{
	int i, j;

	if (name != NULL || name[0] != '\0')
	{
		i = 0;
		while (environ[i] != NULL)
		{
			j = 0;
			while (*name == environ[i][j] && *name != '\0')
			{
				name++;
				j++;
			}
			if ((environ[i][j]) == '=')
				return (&environ[i][j + 1]);
			i++;
		}
	}
	return (NULL);
}

/**
* printPathDir - function that calls getenv function by passing
* PATH string and converts the path dir to a string array
* Return - string array of path dirs
*/
char **printPathDir(void)
{
	char *token, **dirArray, *pointerToPath;
	int i;

	dirArray = malloc(sizeof(char *) * 32);
	if (!dirArray)
	{
		printf("memory allocation error\n");
		exit(1);
	}
	pointerToPath = _getenv("PATH");
	token = strtok(pointerToPath, ":");
	char **temp = &dirArray[0];
	while (token)
	{
		*dirArray = malloc(256 * sizeof(char));	
		if (!*dirArray)
		{
			printf("memory allocation error\n");
			free(dirArray);
			exit(1);
		}
		*dirArray = _strdup(token);
		*dirArray++;
		token = strtok(NULL, ":");
	}
	return (temp);
/*	i = 0;
for printing the values
	while (temp[i] != NULL)
	{
		printf("printing\n");
		printf("%s\n",temp[i]);
		i++;
	}*/
}
/* uncomment this for testing the output
int main(void)
{

	char **temp;
	int i;

	temp = printPathDir();
	i = 0;
	while (temp[i] != NULL)
	{
		printf("printing\n");
		printf("%s\n",temp[i]);
		i++;
	}

} */

