#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
* *_strdup - returns a pointer to a newly allocated space in memory
* @str: the string
*Return: NULL if str = NULL, p if copied succesfully
*
*
*/
char *_strdup(char *str)
{
	int j, size;
	char *p;

	if (str == NULL)
	{
		return (NULL);
	}
	for (size = 0; str[size] != '\0'; size++)
	{
		;
	}
	p = malloc(sizeof(char) * size + 1);
	if (p == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < size; j++)
	{
		p[j] = str[j];
	}
	p[j] = '\0';
	return (p);
}
/**
* *str_concat - concatenates two strings
* @s1: first string
* @s2: second string
*Return: returns the concatenated string
*
*/
char *str_concat(char *s1, char *s2)
{
	long int i, j, s1len, s2len;
	char *a;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	s1len = charlen(s1);
	s2len = charlen(s2);
	a = malloc(sizeof(char) * s1len + s2len + 1);
	if (a == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < s1len; i++)
	{
		a[i] = s1[i];
	}
	for (j = 0; j < s2len; j++)
	{
		a[i] = s2[j];
		i++;
	}
	a[i] = '\0';
	return (a);
}
/**
* charlen - gets the length of a string
* @s: the string
*Return: returns the length of the string
*
*
*/
int charlen(char *s)
{
	int size;

	for (size = 0; s[size] != '\0'; size++)
	{
		;
	}
	return (size);
}
/**
* _strcmp - compares two strings
* @s1 : first string
* @s2: second string
*Return: returns the result
*
*
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
