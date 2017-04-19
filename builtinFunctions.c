#include "shell.h"

int getMyBuiltins(env **h, char **cmds)
{
	int i;

	builtinFunc builtIns [] = {
/*		{"cd", changeMyDir},
		{"env", _getenv},*/
		{"setenv", _setEnv},
		{"env", print_env_list},
		{NULL, NULL}
	};
	for (i = 0; builtIns[i].cmd != NULL; i++)
	{
		if(_strcmp(cmds[0], builtIns[i].cmd) == 0)
			return(builtIns[i].f(h, cmds));
	}
	return (0);
}
