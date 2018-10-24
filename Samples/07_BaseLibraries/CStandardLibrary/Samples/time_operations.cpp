#define _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <cstdio>

void time_operations()
{
	time_t t;
	t = time(&t);
	char buff[100];

	tm *local_tm = localtime(&t);
	strftime(buff, sizeof(buff), "%H:%M %d.%m.%Y", local_tm);
	printf("strftime local: %s\n", buff);

	tm *utc_tm = gmtime(&t);
	strftime(buff, sizeof(buff), "%H:%M %d.%m.%Y", utc_tm);
	printf("strftime utc: %s\n", buff);

	local_tm = localtime(&t);

	printf("%d\n", local_tm->tm_yday);
}