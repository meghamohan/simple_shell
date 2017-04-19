#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define PROMPT "MyShell$  "
#define NOCOMMAND " : Command not found\n"
extern char **environ;
int writePrompt(void);
int command_error(void);
/* string.c - functions to manipulate strings */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strncat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int checkmode(void);
char *path_split(char *input);
int statcheck(const char *path_tok);
void exit(int n);
void printenviron(void);
void execute(char **command);

char *_getenv_val(const char *name);

/* tokenizer.c - allocate memory for tokens and split */
void tokenizer(char *input, char **command);
char **path_tok(char *path_val, char **input_tok);
void clear_buffer(char *buffer);
#endif
