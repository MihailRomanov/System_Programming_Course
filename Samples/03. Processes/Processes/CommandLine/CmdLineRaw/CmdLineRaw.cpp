#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Not valid arguments count");
		return -1;
	}

	printf(argv[1]);
}

