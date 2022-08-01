#include "main.h"

int shell_loop(void)
{
	char *prompt = NULL;
	char **commands = NULL;
	char **ret_cmd = NULL;
	while (1)
	{
		_puts(_getenv("USER"));
		_putchar('@');
		_puts("hsh> ");
		prompt = readline();
		commands = token_cmd(prompt);
		ret_cmd = cmd_check(commands);
		free(prompt);
		free(commands);
		free(ret_cmd);
	}
	return (EXIT_SUCCESS);
}
