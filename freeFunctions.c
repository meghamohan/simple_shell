#include "shell.h"

/**
 *freeEnvironList - free the list
 *@env1: head of the nodes or start of them
 *Return: void
 */
void freeEnvironList(env *env1)
{
	env *current;

	if (env1 == NULL)
		return;

	while (env1 != NULL)
	{
		current = env1;
		env1 = env1->next;
		free(current);
	}
}

void freeStringArray(char **strArray)
{
	int i = 0;

	while (strArray[i] != NULL)
	{
		free(strArray[i]);
		i++;
	}
	free(strArray);
}
