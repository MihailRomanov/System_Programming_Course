#include <cstdio>
#include <unistd.h>
#include <memory.h>

int main()
{
	char str1[] = "Hello, world!\n";
	char str2[100];
	memset(str2, 0, sizeof(str2));

	int pipes[2];
	int r = pipe(pipes);

	if (r == 0)
	{
		write(pipes[1], str1, sizeof(str1));
		ssize_t readed = read(pipes[0], str2, sizeof(str2));

		printf("%d %s", readed,  str2);
	}

	close(pipes[0]);
	close(pipes[1]);

	return 0;
}