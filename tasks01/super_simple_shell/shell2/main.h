#ifndef MAIN_H
#define MAIN_H

extern char **environ;
#define BUFF_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <limits.h>

char *_strdup(char *str);
char *line_read(void);
char *_getenv(const char *name);
void print_prompt(void);
char **line_parse(char *prompt);
int cmd_checker(char **commands);
void path_exc(char **commands);
int is_builtint(char **commands);
int command_verify(char **commands);
int exec(char **commands);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void _puts(char *str);
int _putchar(char c);

#endif /*MAIN_H*/
