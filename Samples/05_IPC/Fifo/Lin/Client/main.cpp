#include <cstdio>
#include "../Server/common.h"
#include <fcntl.h>
#include <unistd.h>


int main()
{
	printf("Connect to server\n");
	int f = open(fifoname, O_RDONLY);

	printf("Connected\n");

	message m;
	read(f, &m, sizeof(m));

	printf("Server %d (started %d:%d)\n", m.server_id, m.server_start.tm_hour, m.server_start.tm_min);

	close(f);
}