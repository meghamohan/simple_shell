# C Shell

<img src="https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.png" alt="shell image">

## Description

This project is aimed to replicate many of the function performed by a bash shell. This is created as a part of Holberton School curriculm. The project aims at learning how to build a simple shell ,understanding the concept of pid and ppid, understanding the difference between function and system calls, learning to create process, using the execve command, understanding about environ variables, implementing functions such as getline, strtok and built in functions like cd, setenv, unsetenv etc.

### List of allowed functions and system calls
* access
* chdir
* close
* closedir
* execve
* exit
* fork
* free
* fstat
* getcwd
* getline
* kill
* lstat
* malloc
* open
* opendir
* perror
* read
* readdir
* signal
* stat
* strtok
* wait
*  waitpid
* wait3
* wait4
* write
* _exit

### How to compile
C shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

### File Descriptions
* `shell.h` : Header file which contains all libraries, structs and function prototypes

* `main.c` : The entry point where the command is read, parsed and executed

* `helperFunctionsStr.c` : helper functions for string manipulations like `char *str_concat(char *s1, char *s2)`, `int _strlen(char *s)`, `char *_strdup(char *str)`, `void _strcpy(char *dest,const char *src)`, `int _strcmp(const char *s1,const char *s2)`
* `envList.c` : contain functions related to environ variables and its manipulations like `_getEnv()`, `createEnvList()`, `addEnvNode()` etc.

* `envList2.c` : contain builtin function related to environ variables like `print_env_list()`, `setEnv()`

* `freeFunctions.c` : functions for freeing memory like `void freeEnvironList(env *envList)`, `void freeStringArray(char **strArray)`, `void freeTokenizedArray(char **strArray)`

* `writeFunc.c` : functions frelated to stdoutput like `int writePrompt(void)`, `int _putchar(char c)`, `void printString(char *str)`

* `builtinFunctions.c` : function `int getMyBuiltins(env **h, char **cmds)` that checks if the input command is a builtin command or not and points to the corresponding builtin command function if it matches the string in the builtin struct.
### Team Members

Halina Veratsennik: [github account](https://github.com/halinav00), [twitter](https://twitter.com/HalinaV)

Megha Mohan: [github account](https://github.com/meghamohan), [twitter](https://twitter.com/meghamohan1989)

