#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
		return -1;
	
	int error_code = atoi(argv[1]);

	return error_code;
}
