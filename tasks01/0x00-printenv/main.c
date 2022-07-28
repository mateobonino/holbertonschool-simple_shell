#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

int main(void)
{
	while (*environ)
	{
		printf("%s\n", *environ);
		environ++;
	}
	return (0);
}
