#include <stdlib.h>
#include <Windows.h>


DWORD WINAPI a(LPVOID)
{
    int n[10000000];
    n[0] ++;
    return 0;
}


int main()
{
    //int n[10000000];
    CreateThread(NULL, 0/*40000000*/, a, 0, 0, 0);
    Sleep(10000);
}