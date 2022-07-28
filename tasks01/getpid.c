#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int my_pid = getppid();

	printf("Pid is: %d\n", my_pid);
	return (0);
}
