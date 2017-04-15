#include "shell.h"

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

