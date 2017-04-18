#include "shell.h"

/*void freeEnvironList(env *envList)
{
	env temp;

        while (*envList != NULL)
	{
		temp = envList;
		envList = temp->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
	free(envList);
}*/

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
