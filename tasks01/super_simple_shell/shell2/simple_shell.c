#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <limits.h>

int main(void)
{
	char **commands;
	char *prompt;
	char **exec_commands = NULL;
	size_t size = 1024;
	size_t child_pid;
	int status;
	while (1)
	{
		print_prompt();
		prompt = line_read();
		commands = line_parse(prompt);
		cmd_checker(commands);
		
	}
	return (0);
}
