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

	if (feof(stdin) || !status)
	{
		free(cmd);
		if (isatty(STDIN_FILENO))
			putchar('\n');
		exit(0);
	}
	if (!isatty(STDIN_FILENO))
		status = 0;
	if (strcmp(cmd, "\n") == 0)
		return (NULL);
	while (cmd[i] != '\n')
	{
		if (cmd[i] != ' ' && cmd[i] != '\t')
			return (cmd);
		i++;
	}
	return (NULL);
}
