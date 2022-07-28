#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char **argv, char **envp)
{
	char *path, *temp, *fpath;
	struct stat st;

	path = *envp;
	temp = strdup(path);
	temp = strtok(temp, "/");
	while (temp != NULL)
	{
		fpath = strdup(temp);
		printf("%s\n", fpath);
		temp = strtok(NULL, "/");
		break;
	}
	return (-1);
}
