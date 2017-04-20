#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFSIZE 1024
#define PROMPT "myShell$ "

extern char **environ;

/**
 * struct envNode - singly linked list of env variables
 * @key: Key of environmental variable
 * @value: value of the env variable
 * @next: points to the next node
 */

typedef struct envNode
{
	char *key;
	char *value;
	struct envNode *next;
} env;

/**
 * struct builtinStruct - structure for builtin functions
 * @cmd: command
 * @f: pointer to function associated with command
 */
typedef struct builtinStruct
{
	char *cmd;
	int (*f)();
} builtinFunc;

/* builtinFunctions.c file */
int getMyBuiltins(env **h, char **cmds);

/* file envList.c - functions */
env *addEnv(env **head, char *env_var);
int create_env_list(env **head);
char *_getenv(env *envVars, const char *name);
char **pathParse(env *envList);
int getExecutablePath(char *cmd);

/* file envList2.c - functions */
int print_env_list(env **h, __attribute__((unused))char **cmds);
int _setEnv(env **h, char **cmds);

/* freeFunctions.c -  functions */
void freeEnvironList(env *head);
void freeTokenizedArray(char **strArray);
void freeStringArray(char **strArray);

/* helperFunctionsStr2.c - functions */
char *str_concat(char *s1, char *s2);

/* helperFunctionsStr.c - functions */
char *_strdup(char *str);
int _strlen(char *s);
void _strcpy(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);

/* main.c - functions */
int handleExecutableCommands(char **tokenizedArray, char **pathDirs);
void excute(char **tokens, char *cmdPath);
char **parseCommand(char *cmd, char **tokens);
void printPrompt(env *head, int InteracFlag);

/* writeFunc.c - functions */
int writePrompt(void);
int _putchar(char c);
void printString(char *str);
#endif

