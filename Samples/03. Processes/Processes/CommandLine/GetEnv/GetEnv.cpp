#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main()
{
	char *home = getenv("homepath");

	if (home != NULL)
		printf(home);
	else
		printf("Variable not found");
}

