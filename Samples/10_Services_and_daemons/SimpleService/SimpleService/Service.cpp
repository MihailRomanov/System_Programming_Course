#include "stdafx.h"


DWORD WINAPI HandlerEx(DWORD dwControl, DWORD dwEventType, LPVOID lpEventData, LPVOID lpContext);

static SERVICE_STATUS ssServiceStatus;
static bool bServiceStopFlag = false;
static SERVICE_STATUS_HANDLE hService;

void WINAPI ServiceMain(DWORD argc, LPTSTR argv[])
{
	hService = RegisterServiceCtrlHandlerEx(ServiceName, HandlerEx, NULL);

	ssServiceStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
	ssServiceStatus.dwCurrentState = SERVICE_RUNNING;
	ssServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN;
	ssServiceStatus.dwWin32ExitCode = 0;
	ssServiceStatus.dwServiceSpecificExitCode = 0;
	ssServiceStatus.dwCheckPoint = 0;
	ssServiceStatus.dwWaitHint = 0;

	SetServiceStatus(hService, &ssServiceStatus);

	while (!bServiceStopFlag)
	{
		Sleep(1000);
	}

	ssServiceStatus.dwCurrentState = SERVICE_STOPPED;
	SetServiceStatus(hService, &ssServiceStatus);
}

DWORD WINAPI HandlerEx(DWORD dwControl, DWORD dwEventType, LPVOID lpEventData, LPVOID lpContext)
{
	switch(dwControl)
	{
		case SERVICE_CONTROL_SHUTDOWN:
		case SERVICE_CONTROL_STOP:
			ssServiceStatus.dwCurrentState = SERVICE_STOP_PENDING;
			ssServiceStatus.dwCheckPoint = 0;
			ssServiceStatus.dwWaitHint = 80000;

			SetServiceStatus(hService, &ssServiceStatus);
			bServiceStopFlag = true;
			
			break;
		
		 case SERVICE_CONTROL_INTERROGATE:
			SetServiceStatus(hService, &ssServiceStatus);
			break;
	
	}

	return 0;
}