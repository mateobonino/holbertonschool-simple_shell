#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char *buff;
	size_t size = 100;
	size_t chars;

	buff = malloc(sizeof(char) * size);
	if (buff == NULL)
	{
		printf("Error\n");
		exit (1);
	}
	printf("$ ");
	chars = getline(&buff, &size, stdin);
	printf("printed: %s", buff);
	printf("chars printed: %d\n", chars);
	return (0);
}
