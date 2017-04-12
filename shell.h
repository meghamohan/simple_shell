#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFSIZE 1024
extern char **environ;

/**
envVar - struct for a single env var
*/
typedef struct envNode
{
	char *key;
	char *value;
	struct envNode *next;
}env;

/**
*shell -struct of all structs needed to load shell
*/
typedef struct shellList
{
	env *envList1;
}shellType;

#endif

