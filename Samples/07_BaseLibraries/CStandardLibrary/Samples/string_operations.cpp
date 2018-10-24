#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string.h>

void string_operations()
{
	char str1[] = "abc";
	char str2[] = "defgh";

	char buff[10];
	memset(buff, 0, sizeof(buff));

	printf("sizeof(str1): %zd\n", sizeof(str1));
	printf("sizeof(str2): %zd\n", sizeof(str2));
	printf("sizeof(buff): %zd\n", sizeof(buff));

	printf("len(str1): %zd\n", strlen(str1));
	printf("len(str2): %zd\n", strlen(str2));
	printf("len(buff): %zd\n", strlen(buff));

	printf("buff : %s\n", buff);
	printf("buff + str1 : %s\n", strcat(buff, str1));
	printf("buff + str1 + str2: %s\n", strcat(buff, str2));

	printf("str1 -> buff : %s\n", strcpy(buff, str1));
	printf("str2 -> buff : %s\n", strcpy(buff, str2));

	printf("cmp: str1 str1: %d\n", strcmp(str1, str1));
	printf("cmp: str1 str2: %d\n", strcmp(str1, str2));
	printf("cmp: str2 str1: %d\n", strcmp(str2, str1));
}