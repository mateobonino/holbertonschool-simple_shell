#ifndef MAIN_H
#define MAIN_H

extern char **environ;
#define C_OUTPUT "\033[H\033[J"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/stat.h>

char *_strdup(char *str);
char *line_read(void);
char *_getenv(const char *name);
void print_prompt(void);
char **line_parse(char *prompt);
int cmd_checker(char **commands);
void path_exc(char **commands);
int is_builtin(char **commands);
char *command_verify(char **commands);
int exec(char **commands);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void _puts(char *str);
int _putchar(char c);
void run_built(char **commands);

#endif /*MAIN_H*/
