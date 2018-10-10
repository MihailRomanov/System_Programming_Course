#include <cstdio>
#include <unistd.h>
#include <memory.h>
#include <wait.h>


int pipes[2];

void client()
{
	close(pipes[1]);

	char str2[100];
	memset(str2, 0, sizeof(str2));

	read(pipes[0], str2, sizeof(str2));

	printf("%d: %s", getpid(), str2);

	close(pipes[0]);
}

void server(pid_t pid)
{
	close(pipes[0]);

	char str[] = "Hello, world!\n";
	char str1[100];

	sprintf(str1, "%d: %s", getpid(), str);

	write(pipes[1], str1, strlen(str1));

	waitpid(pid, NULL, 0);
}

int main()
{
	int r = pipe(pipes);
	if (r != 0) 
		_exit(1);

	pid_t pid = fork();
	if (pid == -1) 
		_exit(1);
	
	if (pid == 0)
		client();
	else
		server(pid);

	return 0;
}
