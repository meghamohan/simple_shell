#include "shell.h"

/*
 *
 */

char *path_split(char *input)
{
	char *path_val, *path_dir, *token_cpy, *slash, *result;

	path_val = getenv("PATH");
	path_dir = strtok(path_val, ":");
	while (path_dir != NULL)
	{
		token_cpy = _strdup(path_dir);
		slash = _strncat(token_cpy, "/");
		result = _strncat(slash, input);
		if (statcheck(result) == 0)
		{
			return (result);
		}
		path_dir = strtok(NULL, ":");
	}
/*free(*tokens);*/
	return (NULL);
}
