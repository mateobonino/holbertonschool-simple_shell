#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(void)
{
	int fd = 0, read_val = 0;
	char *lookFor = "ID";
	int lookLen = strlen(lookFor);
	char *buff = NULL;

	buff = malloc(1024);
	if (!buff)
		return (1);
	fd = open("/etc/os-release", O_RDONLY);
	if (fd == -1)
		return (1);
	read_val = read(fd, buff, 1024);
	if (read_val == -1)
		return (1);
	while (buff != NULL)
	{
		if (strcmp(lookFor, buff) == 0)
			printf("%s\n", buff);
		buff++;
	}
	close(fd);
	return (0);
}
