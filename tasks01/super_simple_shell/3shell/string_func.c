#include "main.h"
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
* *_strcat - concatenates two strings
* @dest : first string
* @src: second string
*Return: returns the concatenated string
*
*
*/
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;

	while (dest[i++])
	{
		j++;
	}
	for (i = 0; src[i]; i++)
	{
		dest[j++] = src[i];
	}
	return (dest);
}
/**
* _strlen - gets the length of a given string using pointers
* @s: str to get length of
*
*Return: returns the string length
*
*
*/
int _strlen(char *s)
{
	int i;

	i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
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
/**
* _puts - prints a string
* @str: string to print
*
*Return: no return, void type function
*
*
*/
void _puts(char *str)
{

	while (*str != '\0')
	{
		_putchar(*str++);
	}
}
