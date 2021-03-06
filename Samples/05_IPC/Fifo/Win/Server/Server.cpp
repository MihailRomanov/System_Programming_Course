#include <stdio.h>
#include <Windows.h>

#include "common.h"

int main()
{
	message m;
	m.id = GetCurrentProcessId();
	GetLocalTime(&m.starttime);

	HANDLE pipe = 
		CreateNamedPipeA(pipename, PIPE_ACCESS_OUTBOUND, PIPE_TYPE_BYTE, 
			1, 0, 0, 0, NULL);

	if (pipe == INVALID_HANDLE_VALUE)
	{
		printf("Can't create named pipe (%d)\n", GetLastError());
		return 1;
	}
	
	printf("Wait client\n");

	if (ConnectNamedPipe(pipe, NULL))
	{
		printf("Client connected\n");
		WriteFile(pipe, &m, sizeof(m), NULL, NULL);
	}


	CloseHandle(pipe);
}

