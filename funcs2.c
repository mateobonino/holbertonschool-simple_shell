#include "main.h"
/**
* sh_read - reads a line from the prompt entered by user
* Return: the line
*/
char *sh_read(void)
{
	int i = 0, j = 0;
	char *cmd = NULL;
	size_t size;

	fflush(stdin);
	int status = getline(&cmd, &size, stdin);

	if (feof(stdin) || !status)
	{
		free(cmd);
		putchar('\n');
		exit(0);
	}
	if (strcmp(cmd, "\n") == 0)
		return (NULL);
	for (i = 0; cmd[i] != '\n'; i++)
	{
		if (cmd[i] != ' ' && cmd[i] != '\t')
			return (cmd);
	}
	return (NULL);
}
