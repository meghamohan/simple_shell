#include "shell.h"

/**
 *freeEnvironList - frees the list
 *@head: env1 of the nodes or start of them
 *
 */

void freeEnvironList(env *head)
{
	if (head == NULL)
		return;
	if (head->next != NULL)
		freeEnvironList(head->next);
	free(head->key);
	free(head->value);
	free(head);

/*
 *
 *	for (; head != NULL; head = next_node)
 *	{
 *		printf("Free env: %s, %s\n", head->key, head->value);
 *		if (head->next != NULL) {
 *			next_node = head->next;
 *			printf("Next node: %s, %s\n", next_node->key, next_node->value);
 *		}
 *		free(head->key);
 *		free(head->value);
 *		free(head);
 *		printf("After free Next node: %s, %s\n", next_node->key, next_node->value);
 *	}
*/
}

/**
 * freeTokenizedArray - function to free tokenized array
 * @strArray: pointer to array of strings
 */

void freeTokenizedArray(char **strArray)
{
	if (strArray == NULL)
		return;
	free(strArray[0]);
	free(strArray);
}

/**
 * freeStringArray - function to free array of strings
 * @strArray: pointer to array of strings
 */

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
