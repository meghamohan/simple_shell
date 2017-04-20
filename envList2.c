#include "shell.h"

/**
* print_env_list - prints the environ list
* @h: environ list to be printed
* @cmds: pointer to array of commands
* Return: returns the number of variables printed, 0 - otherwise
*/

int print_env_list(env **h, __attribute__((unused))char **cmds)
{
	env *temp = *h;

	if (!temp)
	{
		perror("error\n");
		return (0);
	}
	while (temp != NULL)
	{
		printString((temp)->key);
		_putchar('=');
		printString((temp)->value);
		_putchar('\n');
		temp = (temp)->next;
	}
	return (1);
}

/**
 * _setEnv - function to set a new env value
 * @h: pointer to head
 * @cmds: pointer to array or commands
 * Return: 1
 */

int _setEnv(env **h, char **cmds)
{
	char *str1, *str;
	env **tmp;
	
	if (!cmds[1] || !cmds[2])
	{
		perror("environ value cannot be null\n");
		return (0);
	}
	str1 = str_concat(cmds[1], "=");
	str = str_concat(str1, cmds[2]);
	tmp = h;
	addEnv(tmp, str);
	free(str); free(str1);
	return (1);
}
