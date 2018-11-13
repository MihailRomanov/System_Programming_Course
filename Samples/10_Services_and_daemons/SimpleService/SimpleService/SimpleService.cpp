// SimpleService.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void WINAPI ServiceMain(DWORD argc, LPTSTR argv[]);


int _tmain(int argc, _TCHAR* argv[])
{

	SERVICE_TABLE_ENTRY ServiceTable[] = 
	{
		{ ServiceName, ServiceMain },
		{ NULL, NULL }
	};

	if (!StartServiceCtrlDispatcher(ServiceTable))
	{
		printf("Service not Started!");
		return -1;
	}

	return 0;
}

