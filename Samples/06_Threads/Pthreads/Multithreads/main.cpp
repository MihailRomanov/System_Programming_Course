#include <cstdio>
#include <pthread.h>

const int MAX_THREADS = 20;
void *proc(void *);

int main()
{
	pthread_t threads[MAX_THREADS];
	int args[MAX_THREADS];

	printf("Start thread creation\n");
	
	for (int i = 0; i < MAX_THREADS; i++)
	{		
		args[i] = i;
		pthread_create(&threads[i], NULL, proc, &args[i]);

		//pthread_create(&threads[i], NULL, proc, &i);
	}
	printf("End thread creation\n");

	printf("Wait threads\n");
	for (int i = 0; i < MAX_THREADS; i++)
	{
		pthread_join(threads[i], NULL);
	}
	printf("All threads end\n");

	return 0;
}

void *proc(void * o)
{
	int threadNum = *((int*)o);

	printf("%d\n", threadNum);

	return NULL;
}