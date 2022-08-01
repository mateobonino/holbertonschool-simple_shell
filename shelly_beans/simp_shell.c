#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *args[] = {" ", NULL};
	size_t characters;
	size_t bufsize = 32;
	char *buffer = malloc(bufsize * sizeof(char));

	printf("#cisfun$ ");

	characters = getline(&buffer,&bufsize, stdin);
	buffer = strtok(buffer, "\n");
	args[0] = buffer;

	if (execve(args[0], args, NULL) == -1)
	{
		perror("Error: ");
		return (-1);
	}

	free(buffer);
	return (0);
}
