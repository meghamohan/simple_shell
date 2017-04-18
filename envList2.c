#include "shell.h"

/**
* print_env_list - prints the environ list
* @h: environ list to be printed
* Return - returns the number of variables printed
*/
int print_env_list(env *h, __attribute__((unused))char** cmds)
{
	unsigned int n;env *temp = h;
	n = 0;

	if (!temp)
	{
		perror("error\n");
		return(0);
	}
	while (temp != NULL)
	{
		printString(temp->key);
		_putchar('=');
		printString(temp->value);
		_putchar('\n');
		n++;
		temp = (temp)->next;
	}
	return (1);
}

