#ifndef MAIN_H
#define MAIN_H

#define C_OUTPUT "\033[H\033[J"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/stat.h>

extern char **environ;
char *_strdup(char *str);
char *_getenv(const char *name);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void _puts(char *str);
int _putchar(char c);

#endif /*MAIN_H*/
