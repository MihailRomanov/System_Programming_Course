#include <cstdlib>

int main(int argc, char *argv[])
{
	if (argc != 2)
		exit(-1);

	int error_code = atoi(argv[1]);

	exit(error_code);
}