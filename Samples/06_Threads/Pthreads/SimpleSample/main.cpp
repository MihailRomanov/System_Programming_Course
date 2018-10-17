#include <cstdio>
#include <pthread.h>
#include <unistd.h>

void* proc(void *);

int main()
{
	pthread_t thread;

	printf("Start thread\n");
	pthread_create(&thread, NULL, proc, NULL);
	printf("Thread started\n");

	printf("Wait\n");
	sleep(3);
	printf("End of waiting\n");

	return 0;
}

void* proc(void *)
{
	printf("Proc\n");

	return NULL;
}