#include "main.h"

int main(void)
{
	char *prompt = NULL;
	char **commands = NULL;
	char **ret_cmd = NULL;
	_puts(C_OUTPUT);
	while (1)
	{
		_puts(_getenv("USER"));
		_putchar('@');
		_puts("sh> ");
		prompt = readline();
		if (prompt == "\n")
		{
			free(prompt);
			continue;
		}
		commands = token_line(prompt);
		ret_cmd = cmd_check(commands);
		free(prompt);
		free(commands);
		free(ret_cmd);
	}
	return (0);
}
