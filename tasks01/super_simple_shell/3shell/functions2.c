#include "main.h"

int exec(char **commands)
{
	pid_t my_pid;
	int status;

	my_pid = fork();
	if (my_pid == -1)
	{
		perror("Error: fork failed\n");
		return (1);
	}
	else if (my_pid == 0)
	{
		execve(commands[0], commands, NULL);
	}
	else
		wait(&status);
	return (0);
}

int is_builtin(char **commands)
{
	int ex_cmd = _strcmp(commands[0], "exit");
	int cd_cmd = _strcmp(commands[0], "cd");
	int env_cmd = _strcmp(commands[0], "env");
	if (_strcmp(commands[0], "exit") == 0)
		return (0);
	else if (_strcmp(commands[0], "cd") == 0)
		return (0);
	else if (_strcmp(commands[0], "env") == 0)
		return (0);
	else
		return (1);
}

void run_built(char **commands)
{
	printf("%s\n", commands[0]);
}

char *command_verify(char **commands)
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
			free(temp);
			return (fpath);
		}
		temp = strtok(NULL, ":");
	}
	free(temp);
	free(fpath);
	return (NULL);
}
