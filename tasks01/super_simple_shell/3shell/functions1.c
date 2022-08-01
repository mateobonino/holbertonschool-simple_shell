#include "main.h"

char **line_parse(char *prompt)
{
	char **tokens, *token;
	int size = 1024, i = 0;

	tokens = malloc(sizeof(char *) * size);
	if (tokens == NULL)
	{
		free(tokens);
		return (NULL);
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
	size_t size = 1024;
	status = getline(&cmd, &size, stdin);

	if (feof(stdin) || status == NULL)
	{
		printf("\n");
		free(cmd);
		exit(0);
	}
	return (cmd);
}
