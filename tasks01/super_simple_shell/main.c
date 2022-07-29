#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
	char *commands[] = {"", NULL};
	char *ex = "exit";
	char *prompt;
	size_t size = 1024;
	size_t child_pid;
	int status;

	while (1)
	{
		printf("#cisfun$ ");
		getline(&prompt, &size, stdin);
		prompt = strtok(prompt, "\n");
		commands[0] = prompt;
		child_pid = fork();
		if (strcmp(commands[0], ex) == 0)
			exit(0);
		if (child_pid == -1)
		{
			perror("Error: ");
		}
		else if (child_pid == 0)
		{
			if (execve(commands[0], commands, NULL) == -1)
			{
				perror("Error: \n");
				return (1);
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
