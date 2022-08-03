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
			free(commands);
			continue;
		}
	}
	return (EXIT_SUCCESS);
}
