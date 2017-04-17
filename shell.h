#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BUFFSIZE 1024
#include <sys/types.h>
#include <sys/wait.h>
#define PROMPT "myShell$ "
extern char **environ;

/**
* envVar - struct for a single env var
*/
typedef struct envNode
{
	char *key;
	char *value;
	struct envNode *next;
}env;
/**
* struct for builtin function
**/
typedef struct builtinStruct
{
	char * cmd;
	int (*f)();
} builtinFunc;

/* function prototypes */
char *str_concat(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *str);
void _strcpy(char *dest,const char *src);
int _strcmp(const char *s1,const char *s2);

env * addEnv(env **head, char *env_var);
int create_env_list(env **head);
size_t print_env_list(env *h);
char *_getenv(env *envVars, const char *name);
char **pathParse(env *envList);
int getExecutablePath(char *cmd);

int writeIt(void);
void freeEnvironList(env **envList);
void freeStringArray(char **strArray);
#endif

