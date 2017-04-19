#include "shell.h"

/**
 *
 */

int statcheck(const char *path_tok)
{
	struct stat buf;

	if (stat(path_tok, &buf) == 0)
	{
		return (0);
	}
	else
		return (1);
	return (0);
}
