#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char *varName = "PATH";
	printf("%s\n", _getenv("PATH"));
	return (0);
}
