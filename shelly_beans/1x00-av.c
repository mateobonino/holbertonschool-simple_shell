#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(__attribute__((unused))int ac, char *av[])
{
	int PEPE1 = 0;

	while (av[PEPE1] != NULL)
	{
		printf("%s\n", av[PEPE1]);
		PEPE1++;
	}
	
	return (0);
}
