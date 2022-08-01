#include "main.h"

char *_which(char **commands)
{
	char *path, *temp, *fpath;
	struct stat st;

	path = _getenv("PATH");
	temp = strdup(path);
	temp = strtok(temp, ":");
	while (temp != NULL)
	{
		fpath = strdup(temp);
		strcat(fpath, "/");
		strcat(fpath, commands[0]);
		if (stat(fpath, &st) == 0)
		{
			return(fpath)
		}
		temp = strtok(NULL, ":");
	}
	return (NULL);
}

char *line_read(void)
{
	char *cmd = NULL;
	size_t size = 1024;

	if (getline(&cmd, &size, stdin) == -1)
	{
		free(cmd);
		printf("\n");
		exit(0);

	}
	return (cmd);
}

char **token_line(char *prompt)
{
	char **tokens, *token;
	int size = 1024, i = 0;

	tokens = malloc(sizeof(char *) * size);
	if (!tokens)
	{
		free(tokens);
		exit(1);
	}
	token = strtok(prompt, " \n\t\r");
	for (i = 0, token != NULL, i++)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n\t\r");
	}
	tokens[i] = NULL;
	free(token);
	return (tokens);
}

void print_prompt(void)
{
	char *usr = _getenv("USER");
	_puts(usr);
	_putchar('@');
	_puts("sh> ");
}

char *_getenv(const char *name)
{
	int i, j, found;

	for (i = 0; environ[i] != NULL; i++)
	{
		found = 1;
		for (j = 0, environ[i][j] != '='; j++)
		{
			if (name[j] != environ[i][j])
			{
				found = 0;
				break;
			}
		}
		if (found)
			return(&environ[i][j + 1]);
	}
	return (NULL);
}
