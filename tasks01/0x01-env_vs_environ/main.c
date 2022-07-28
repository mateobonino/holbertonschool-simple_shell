#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	printf("Environ address: %p\n", &environ);
	printf("Env (third parameter) address: %p\n", &env);
	return (0);
}
