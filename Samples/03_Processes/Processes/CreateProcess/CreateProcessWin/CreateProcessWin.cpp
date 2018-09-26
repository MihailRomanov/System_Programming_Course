#include <Windows.h>
#include <stdio.h>

int main()
{
	PROCESS_INFORMATION pInfo;
	STARTUPINFO startupInfo;
	
	ZeroMemory(&startupInfo, sizeof(startupInfo));
	startupInfo.cb = sizeof(startupInfo);

	TCHAR cmdLine[] = TEXT("calc.exe");

	if (CreateProcess(NULL, cmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &pInfo))
	{
		printf("Process created");
	}
	else
	{
		DWORD error = GetLastError();
		printf("Error %u", error);
	}

}

