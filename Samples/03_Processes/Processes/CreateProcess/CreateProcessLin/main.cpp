#include <cstdio>
#include <unistd.h>

int main()
{
	__pid_t id_1 = getpid();

	__pid_t id = fork();

	__pid_t id_2 = getpid();


	printf("Before = %u | After = %u | Get from fork() = %u\n", id_1, id_2, id);

	if (id != 0)
	{
		printf("Main process %u\n", id);
		sleep(4);
	}
	else
	{
		printf("Child process %u\n", id);
	}


	return 0;
}