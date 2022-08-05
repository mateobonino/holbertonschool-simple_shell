#include "main.h"
/**
* main - checks the code
* @ac: the number of args
* @av: array of args
* Return: always 0
*/
int main(int ac __attribute__((unused)), char **av)
{
	/*int fork_status = 0;*/
	char *prompt = NULL, **commands = NULL, **checked_args = NULL;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		print_prompt();
		prompt = sh_read();
		if (!prompt)
			continue;
		commands = parse_cmd(prompt);
		if (_strcmp(commands[0], "exit") == 0)
		{
			free(prompt);
			free(commands);
			exit(0);
		}
		if (_strcmp(commands[0], "env") == 0)
		{
			free(commands);
			free(prompt);
			_printenv();
			continue;
		}
		if (_strcmp(commands[0], "clear") == 0)
		{
			_puts(C_TERMINAL);
			continue;
		}
		checked_args = checked(commands, av);
		if (checked_args == NULL)
			continue;
		free(commands);
		free(prompt);
	}
	free(commands);
	return (EXIT_SUCCESS);
}
