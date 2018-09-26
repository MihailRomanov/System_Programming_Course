#include <cstdio>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	__pid_t id = fork();

	if (id != 0)
	{
		execl("/usr/bin/mc", "");
	}

	printf("mc started");
}