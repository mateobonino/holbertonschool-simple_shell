#include "main.h"

int exec(char **commands)
{
	pid_t my_pid;
	size_t status;

	my_pid = fork();
	if (my_pid == -1)
	{
		perror("Error: fork failed\n");
		return (1);
	}
	else if (my_pid == 0 || my_pid > 0)
	{
		execve(commands[0], commands, NULL);
		exit(0);
	}
	else
		wait(&status);
	return (1);
}

int is_builtin(char **commands)
{
	if (_strcmp(commands[0], "exit") == 0)
		return(1);
	else if (_strcmp(commands[0], "cd") == 0)
		return (1);
	else if (_strcmp(commands[0], "env") == 0)
		return (1);
	return (0);
}

int command_verify(char **commands)
{
	char *path, *temp, *fpath;
	struct stat st;

	path = _getenv("PATH");
	temp = _strdup(path);
	temp = strtok(temp, ":");
	while (temp != NULL)
	{
		fpath = _strdup(temp);
		_strcat(fpath, "/");
		_strcat(fpath, commands[0]);
		if (stat(fpath, &st) == 0)
		{
			return (0);
			break;
		}
		temp = strtok(NULL, ":");
	}
	return (1);
}
