#include "shell.h"

/**
 *freeEnvironList - frees the list
 *@env1: env1 of the nodes or start of them
 *Return: void
 */
void freeEnvironList(env *head)
{
	if (head == NULL)
		return;
	if (head->next != NULL)
		freeEnvironList(head->next);
	free(head->key);
	free(head);

	/*
	for (; head != NULL; head = next_node)
	{
		printf("Free env: %s, %s\n", head->key, head->value);
		if (head->next != NULL) {
			next_node = head->next;	
			printf("Next node: %s, %s\n", next_node->key, next_node->value);
		}
		free(head->key);
		free(head->value);
		free(head);
		printf("After free Next node: %s, %s\n", next_node->key, next_node->value);
	}*/
}

void freeTokenizedArray(char **strArray)
{
	if (strArray == NULL)
		return;
	free(strArray[0]);
	free(strArray);
}

void freeStringArray(char **strArray)
{
	int i = 0;
	if (strArray == NULL)
		return;

	while (strArray[i])
	{
		free(strArray[i]);
		i++;
	}
	/*free(strArray[i]);*/

	free(strArray);
}
