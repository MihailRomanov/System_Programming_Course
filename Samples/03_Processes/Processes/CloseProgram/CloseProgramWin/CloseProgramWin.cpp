#include <Windows.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
		ExitProcess(-1);

	int error_code = atoi(argv[1]);
		
	ExitProcess(error_code);
}