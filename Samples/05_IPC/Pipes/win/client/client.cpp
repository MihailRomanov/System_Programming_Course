#include <stdio.h>
#include <Windows.h>

int main(int argc, char * argv[])
{	
	HANDLE h = (HANDLE) atoll(argv[1]);

	char buffer[100];
	ZeroMemory(buffer, sizeof(buffer));

	DWORD readed;

	ReadFile(h, buffer, sizeof(buffer), &readed, NULL);
	CloseHandle(h);

	printf("%s", buffer);

	return 0;
}