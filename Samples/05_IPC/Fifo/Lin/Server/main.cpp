#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include "common.h"


int main()
{
	message m;
	
	time_t t;
	time(&t);

	localtime_r(&t, &m.server_start);
	m.server_id = getpid();

	mkfifo(fifoname, 0666);

	printf("Wait a client...\n");
	int f = open(fifoname, O_WRONLY);
	printf("Client connected\n");
		
	write(f, &m, sizeof(m));

	close(f);
}