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
1. `shell.h` : Header file which contains all libraries, structs and function prototypes

2. `main.c` : The entry point where the command is read, parsed and executed
Below are the functions present:
	* ``excute()`` - executes the parent and child process
	* ``parseCommand()`` - tokenizes the commandline that is read from the terminal
	* ``handleExecutableCommands()`` - checks if the executable path is valid
	* ``printPrompt()`` - prints prompt, gets a line containing command
	* ``main()`` - the main entry point of shell program

3. `helperFunctionsStr.c` : helper functions for string manipulations
	* ``char *str_concat(char *s1, char *s2)`` : concatenates two strings
	* ``int _strlen(char *s)`` : returns the length of a string
	* ``char *_strdup(char *str)`` : returns a pointer to a newly allocated space with copy of arg
	* ``void _strcpy(char *dest,const char *src)`` : copies a string
	* ``int _strcmp(const char *s1,const char *s2)`` : compares two strings
3. `envList.c` : contain functions related to environ variables and its manipulations 
	* ``_getEnv()`` : gets the value of a specific environ variable
	* ``createEnvList()`` : creates a list of environ variables
	* ``addEnvNode()`` : adds an environ variable to the environ list
	* ``char **pathParse(env *envList)`` : parses each directory from the PATH dir string
	* ``getExecutablePath()`` - checks if the given file is present

4. `envList2.c` : contain builtin function related to environ variables
	* ``print_env_list()`` : prints the environ list
	* ``setEnv()`` : function to set a new env value
	* ``_setEnv()`` - function to set a new env value

5. `freeFunctions.c` : functions for freeing memory
	* ``void freeEnvironList(env *envList)`` :  frees the list
	* ``void freeStringArray(char **strArray)`` : function to free tokenized array
	* ``void freeTokenizedArray(char **strArray)`` : function to free array of strings

6. `writeFunc.c` : functions frelated to stdoutput 
	* ``int writePrompt(void)`` : function that writes to stdoutput
	* ``int _putchar(char c)`` : writes the character to stdout
	* ``void printString(char *str)`` : prints a string

7. `builtinFunctions.c` : has function ``int getMyBuiltins(env **h, char **cmds)`` that checks if the input command is a builtin command or not and points to the corresponding builtin command function if it matches the string in the builtin struct.
