#include "shell.h"
/**
  * writeIt - function that writes to stdoutput
  * @s: string to be written
  * Return: length of string written
  */
int writeIt(void)
{
	int i;

	i = write(1, PROMPT, _strlen(PROMPT));
	return (i);
}
