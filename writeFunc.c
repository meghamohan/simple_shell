#include "shell.h"
/**
  * writePrompt - function that writes to stdoutput
  * Return: length of string written
  */
int writePrompt(void)
{
	int i;

	i = write(1, PROMPT, _strlen(PROMPT));
	return (i);
}

/**
 * _putchar - writes the character to stdout
 * @c: char to print
 *
 * Return: 1 (SUCCESS) and -1 (ERROR)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * printString - prints a string
 * @str: string to print
 *
 */
void printString(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}
