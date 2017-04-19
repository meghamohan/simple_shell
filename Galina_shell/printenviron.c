#include "shell.h"

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
void printenviron(void)
{
	unsigned int i, len;

	i = 0;
	while (environ[i] != NULL)
	{
		len = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 2);
		i++;
	}
}
