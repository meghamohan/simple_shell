#include "shell.h"

/**
 * _strlen - return a length of a string
 * @s : pointer to string
 *
 *Return: counting string character count
 */

int _strlen(char *s)
{
	int c = 0;

	while (s[c] != '\0')
		c++;

	return (c);
}

/**
* _strcmp - function to compare two strings;
* @s1: string one
* @s2: string two
 *
* Return: zero
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
 * _strncat - function to concatenate 2 strings
 * @dest: first string
 * @src: second string
 * @n: number of bytes
 *
 * Return: concatenated string
 */

char *_strncat(char *dest, char *src)
{
	int i, j;

	i = 0;

	while (dest[i] != '\0')
	{
		i++;
	}


	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcpy - pointer to function to print a copy of the string
 * @dest : pointer to destination
 * @src : pointer to source
 *
 * Return: return value - copy of the string \ destination
 */

char *_strcpy(char *dest, char *src)
{
	int i;
	int c = 0;

	while (src[c] != '\0')
	{
		c++;
	}
	for (i = 0; i < c + 1; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}

/*
 *
 */

char *_strdup(char *str)
{
	char *string;
	int i, count = 0;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		count++;

	string = malloc(sizeof(char) * (count + 1));

	for (i = 0; i < count; i++)
		string[i] = str[i];
	string[i] = '\0';
	return(string);
}
