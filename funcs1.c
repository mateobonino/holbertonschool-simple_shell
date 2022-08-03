#include "main.h"
/**
* parse_cmd - tokenizes the prompt given by the user
* @prompt: the prompt entered by user
* Return: the tokenized line
*/
char **parse_cmd(char *prompt)
{
	char **tokens, *token = NULL;
	int size = 1024, i = 0;

	tokens = malloc(sizeof(char *) * size);
	if (!tokens)
	{
		return (NULL);
	}
	token = strtok(prompt, " \n\r\a\t");
	for (i = 0; token != NULL; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n\r\a\t");
	}
	tokens[i] = NULL;
	free(token);
	return (tokens);
}
/**
* prompt_check - checks the content of the prompt
* @prompt: the line entered by user
* Return: 1 in special case, 0 otherwise
*/
int prompt_check(char *prompt)
{
	int i = 0, promptLen = strlen(prompt), spaces = 0;

	for (i = 0; prompt[i] != '\0'; i++)
	{
		if (prompt[i] == ' ')
			spaces++;
	}
	if (spaces == promptLen - 2)
		return (1);
	if (prompt[i] == '\t' && prompt[promptLen - 1] == '\n')
		return (1);
	else if (strcmp(prompt, "clear\n") == 0)
		return (2);
	else
		return (0);
}
/**
* exec_args - execs the args with fork()
* @checked_args: the args to execute
* Return: 0 in success, 1 in failure
*/
int exec_args(char **checked_args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	} else if (child_pid == 0)
	{
		execve(checked_args[0], checked_args, NULL);
		exit(0);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
/**
* cmd_verify - verifies if command exists in the path
* @commands: commands to verify
* Return: the full path of the command
*/
char *cmd_verify(char **commands)
{
	char *path, *temp, *fpath;
	struct stat st;

	path = getenv("PATH");
	temp = strdup(path);
	temp = strtok(temp, ":");
	while (temp)
	{
		fpath = strdup(temp);
		strcat(fpath, "/");
		strcat(fpath, commands[0]);
		if (stat(fpath, &st) == 0)
		{
			return (fpath);
		}
		temp = strtok(NULL, ":");
	}
	free(temp);
	return (NULL);
}
/**
* checked - checks what kind of command entered the user
* @commands: the commands entered by user
* Return: the command
*/
char **checked(char **commands)
{
	char *cmd = NULL;
	struct stat st;

	if (stat(commands[0], &st) == 0)
	{
		/*has path*/
		return (commands);
	}
	else
	{
		/*HAS NOT PATH, CHECKING THE COMMANDS*/
		cmd = cmd_verify(commands);
		if (cmd != NULL)
		{
			/*COMMANDS ARE OK*/
			commands[0] = cmd;
			return (commands);

		}
		else
		{
			perror("Error");
			free(cmd);
		}
	}
	return (commands);
}
