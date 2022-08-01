#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(__attribute__((unused))int ac, char *av[])
{
	int PEPADA, PEPE1 = 0;

	printf("$ ");
	wait(NULL);
	
	PEPADA = getline(*av);

	while (PEPADA > PEPE1)
	{
		printf("%s\n", av[PEPE1]);
		PEPE1++;
	}
	
	return (0);
}
