#include "shell.h"

/**
* *_strdup - returns a pointer to a newly allocated space with copy of arg
* @str: string to copy
* Return: pointer to array or null
**/
char *_strdup(char *str)
{
	char *dup;
	int i, j;

	if (str == NULL)
		return (NULL);
	j = 0;
	while (str[j] != '\0')
		j++;
	j++;
	dup = malloc(sizeof(*str) * j);

	if (dup == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/**
* _strlen - returns the length of a string
* @s: takes in a string
* Return: i, string length
*/
int _strlen(char *s)
{
	int i;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
* _strcpy - copies a string
* @dest: destionation string
* @src: source string
* Return: destination
*/
void _strcpy(char *dest,const char *src)
{
	int i, length;

	printf("strcpy");
	for (length = 0 ; src[length] != '\0' ; length++)
		;
	for (i = 0 ; i < length ; i++)
	{

		dest[i] = src[i];
		printf("%c",dest[i]);
	}
}

/**
* _strcmp - compares two strings
* @s1: takes in first string
* @s2: takes in second string
* Return: i, integer
*/
int _strcmp(const char *s1,const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

