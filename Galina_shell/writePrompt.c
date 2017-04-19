#include "shell.h"

/**
 *
 */

int writePrompt(void)
{
	int i;
	i = write(1, PROMPT, _strlen(PROMPT));
	return(i);
}

/*
 *
 */
int command_error(void)
{
	int i;
	i = write(1, NOCOMMAND, _strlen(NOCOMMAND));
	return(i);
}
