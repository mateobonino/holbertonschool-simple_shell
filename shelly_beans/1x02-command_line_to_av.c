#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(__attribute__((unused))int ac, char *av[])
{
	char * PEPEN = strtok(av, " ");

	while( PEPEN != NULL )
	{
		printf( " %s\n", PEPEN );
		PEPEN = strtok(NULL, " ");
	}
   return 0;
}
