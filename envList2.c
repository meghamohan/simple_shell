#include "shell.h"

/**
* print_env_list - prints the environ list
* @h: environ list to be printed
* Return - returns the number of variables printed
*/
int print_env_list(env *h, __attribute__((unused))char** cmds)
{
	unsigned int n;

	n = 0;
	if (!h)
	{
		perror("error\n");
		return(0);
	}
	while (h != NULL)
	{
		n++;
		h = (h)->next;
	}
	return (1);
}

