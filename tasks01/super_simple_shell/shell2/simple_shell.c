#include "main.h"

int main(void)
{
	char **commands;
	char *prompt;
	_puts(C_OUTPUT);
	while (1)
	{
		print_prompt();
		prompt = line_read();
		commands = line_parse(prompt);
		cmd_checker(commands);
	}
	return (0);
}
