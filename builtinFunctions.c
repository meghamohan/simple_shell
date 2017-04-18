#include "shell.h"

int getMyBuiltins(env *h, char **cmds)
{
	int i;

	builtinFunc builtIns [] = {
/*		{"cd", changeMyDir},
		{"env", _getenv},
		{"exit", exitMyFunction}*/
		{"env", print_env_list},
		{"\0", NULL}
	};
	for (i = 0; builtIns[i].cmd; i++)
	{
		if(_strcmp(cmds[0], builtIns[i].cmd) == 0)
			return(builtIns[i].f(h, cmds));
	}
	return (0);
}
