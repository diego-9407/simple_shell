#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: destination
 * @s2: source
 * Return: 0 on success, lesser or greater if it fails.
 */
int _strcmp(char *s1, char *s2)
{
	int long_of_dest;

	if (s1 == NULL || s2 == NULL)
		return (1);
	if (_strlen(s1) != _strlen(s2))
		return (1);
	for (long_of_dest = 0; s1[long_of_dest] != '\0'; long_of_dest++)
	{
		if (s1[long_of_dest] != s2[long_of_dest])
		{
			return (s1[long_of_dest] - s2[long_of_dest]);
		}
	}
	return (0);
}
/**
 * _strdup - generates a string
 * @str: string to recive
 * Return: a pointer to a newly allocated space in memory
 */
char *_strdup(char *str)
{
	char *copy = NULL;
	int i;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
	{
	}
	copy = malloc((i + 1) * sizeof(char));
	if (copy == NULL)
	{
		free(copy);
		return (NULL);
	}
	for (i = 0; str[i]; i++)
	{
		copy[i] = str[i];
	}
	copy[i] = '\0';
	return (copy);
}
/**
 * _strcat - concatenates 2 strings
 * @dest: destination f the concatenation
 * @src: source of what will be concatenated
 * Return: The destination string concatenated
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{}
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}
/**
 * _strlen - prints the length of a string
 * @s: the string to measure
 *
 * Return: No returning
 */
int _strlen(char *s)
{
	int counter;

	for (counter = 0; s[counter] != '\0'; counter++)
	{}
	return (counter);
}
/**
 * str_cmp_first_chars - compares the first charactes of a string with another
 * @envs: long string
 * @namenv: short string
 * Return: 1 if they are equal in their first chars, 0 if they are not
 */
int str_cmp_first_chars(char *envs, char *namenv)
{
	int i = 0, j = 0;

	for (i = 0; namenv[i]; i++)
	{
	}
	for (j = 0; namenv[j]; j++)
	{
		if (envs[j] != namenv[j])
			break;
	}
	if (i == j)
		return (1);
	else
		return (0);
}
