#include "shell.h"

/*
 *
 */

int checkmode(void)
{
	struct stat interac;
	int mode = -1;

/* check status of mode */
	if (fstat(STDIN_FILENO, &interac) == -1)
	{
		perror("fstat Error:\n");
		exit(EXIT_FAILURE);
	}
/* if in non-interactive mode */
	if ((interac.st_mode & S_IFMT) == S_IFIFO)
	{
		mode = 0;
	}
/* if interactive mode, print prompt*/
	if (mode == -1)
	{
		writePrompt();
	}
	return(0);
}
