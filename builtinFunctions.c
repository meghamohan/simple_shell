#include "shell.h"

/**
 * getMyBuiltins - function to search through built in if input match
 *@h: pointer to head
 *@cmds: pointer to array of commands
 * Return: pointer to function if command match, 0 - otherwise
 */

int getMyBuiltins(env **h, char **cmds)
{
	int i;

	builtinFunc builtIns[] = {
		{"setenv", _setEnv},
		{"env", print_env_list},
		{NULL, NULL}
	};
	for (i = 0; builtIns[i].cmd != NULL; i++)
	{
		if (_strcmp(cmds[0], builtIns[i].cmd) == 0)
			return (builtIns[i].f(h, cmds));
	}
	return (0);
}
