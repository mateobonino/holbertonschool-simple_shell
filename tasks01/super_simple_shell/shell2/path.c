#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	char *path, *temp, *fpath;
	struct stat st;

	if (argc < 2)
	{
		printf("Usage: _which filename\n");
		return (1);
	}
	path = getenv("PATH");
	temp = strdup(path);
	temp = strtok(temp, ":");
	while (temp != NULL)
	{
		fpath = strdup(temp);
		strcat(fpath, "/");
		strcat(fpath, argv[1]);
		if (stat(fpath, &st) == 0)
		{
			printf("%s FOUND IN: %s", argv[1], fpath);
			break;
		}
		temp = strtok(NULL, ":");
	}
	return (-1);
}
