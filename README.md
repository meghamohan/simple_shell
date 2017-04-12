#C Shell

<img src="https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.png" alt="shell image">

## Description

This project is aimed to replicate many of the function performed by a bash shell. This is created as a part of Holberton School curriculm. The project aims at learning how to build a simple shell ,understanding the concept of pid and ppid, understanding the difference between function and system calls, learning to create process, using the execve command, understanding about environ variables, implementing functions such as getline, strtok and built in functions like cd, setenv, unsetenv etc.

###List of allowed functions and system calls
access
chdir
close
closedir
execve
exit
fork
free
fstat
getcwd
getline
kill
lstat
malloc
open
opendir
perror
read
readdir
signal
stat
strtok
wait
waitpid
wait3
wait4
write
_exit

### How to compile
Your shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

### File Descriptions
shell.h : Header file which contains all libraries, structs and function prototypes
helperFunctionsStr.c : helper functions for string manipulations like _Strcpy, _strconcat, _strlen
<TBD>

###Team Members
Halina Veratsennik
Megha Mohan

