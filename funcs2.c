#include "main.h"
/**
* sh_read - reads a line from the prompt entered by user
* Return: the line
*/
char *sh_read(void)
{
	int i = 0, status;
	char *cmd = NULL;
	size_t size = 0;

	fflush(stdin);
	status = getline(&cmd, &size, stdin);

	if (feof(stdin) || status == EOF)
	{
		free(cmd);
		if (isatty(STDIN_FILENO))
			_putchar('\n');
		exit(0);
	}
	if (!isatty(STDIN_FILENO))
		status = 0;
	if (strcmp(cmd, "\n") == 0)
	{
		return (NULL);
	}
	while (cmd[i] != '\n')
	{
		if (cmd[i] != ' ' && cmd[i] != '\t')
			return (cmd);
		i++;
	}
	free(cmd);
	return (NULL);
}
/**
* _getenv - looks for a environment variable
* @name: the variable to look for
* Return: the value if found, NULL otherwise
*/
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
