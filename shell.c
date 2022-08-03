#include "main.h"
/**
* main - checks the code
* @ac: the number of args
* @av: array of args
* Return: always 0
*/
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	int fork_status;
	char *prompt = NULL, **commands = NULL, **checked_args = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "> ", 2);
		prompt = sh_read();
		if (!prompt)
		{
			free(prompt);
			continue;
		}
		prompt = strtok(prompt, "\n");
		commands = parse_cmd(prompt);
		checked_args = checked(commands);
		if (checked_args == NULL)
		{
			printf("\n");
			continue;
		}
		fork_status = exec_args(checked_args);
		if (fork_status == 1)
		{
			free(prompt);
			free_commands(commands);
			continue;
		}
		free_commands(commands);
	}
	free(prompt);
	return (EXIT_SUCCESS);
}

void free_commands(char **commands)
{
	int i = 0;

	for (i = 0; commands[i]; i++)
	{
		free(commands[i]);
	}
	free(commands);
}
