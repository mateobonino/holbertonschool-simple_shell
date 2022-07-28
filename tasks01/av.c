#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int ac, char **av)
{
	int i, len = strlen(*av);
	
	for (i = 1; av[i]; i++)
	{
		printf("%s", av[i]);
		if (av[i + 1] == NULL)
		{
			break;
		}
		printf(" ");
	}
	printf("\n");
	return (0);
}
