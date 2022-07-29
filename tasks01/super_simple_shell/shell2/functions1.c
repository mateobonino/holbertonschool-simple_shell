#include "main.h"

int cmd_checker(char **commands)
{
	int built = 0, cmd = 0;
	int ret = 0;
	struct stat st;

	if (stat(commands[0], &st) == 0)
	{
		exec(commands);
		return (0);
	}
	else
	{
		built = is_builtin(commands);
		if (built)
			run_built(commands);
		cmd = command_verify(commands);
		if (cmd == 0)
			exec(commands);
		else
			exit(1);
	}
	return (0);
}

char **line_parse(char *prompt)
{
	char **tokens, *token;
	int size = 300, i = 0;

	tokens = malloc(sizeof(char *) * size);
	if (tokens == NULL)
	{
		printf("Error\n");
		exit(1);
	}
	token = strtok(prompt, " \n\t\r");
	for (i = 0; token; i++)
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
	write(1, "")
	write(1, "$ ", 2);
}

char *_getenv(const char *name)
{
	int i, j, found;

	for (i = 0; environ[i]; i++)
	{
		found = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] != environ[i][j])
			{
				found = 0;
				break;
			}
		}

		if (found)
			return (&environ[i][j + 1]);
	}
	return (NULL);
}
char *line_read(void)
{
	int status;
	char *cmd = NULL;
	size_t size = BUFF_SIZE;
	status = getline(&cmd, &size, stdin);

	if (status == -1)
	{
		if (status == EOF)
		{
			printf("\n");
			exit (0);
		}
		else
		{
			printf("Error\n");
			exit (1);
		}
	}
	return (cmd);
}
