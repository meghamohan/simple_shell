#include "shell.h"

/**
* print_env_list - prints the environ list
* @h: environ list to be printed
* Return - returns the number of variables printed
*/
int print_env_list(env **h, __attribute__((unused))char** cmds)
{
	unsigned int n;env *temp = *h;
	
	n = 0;
	if (!temp)
	{
		perror("error\n");
		return(0);
	}
	while (temp != NULL)
	{
		printString((temp)->key);
		_putchar('=');
		printString((temp)->value);
		_putchar('\n');
		n++;
		temp = (temp)->next;
	}
	printf("count of envs: %d\n",n);
	return (1);
}

int _setEnv(env **h, char** cmds)
{
	char *str;
	env **tmp;

/*	create_env_list(h);*/
	str = str_concat(cmds[1], "=");
	str = str_concat(str, cmds[2]);
	tmp = h;
	addEnv(tmp, str);
	return (1);
}
