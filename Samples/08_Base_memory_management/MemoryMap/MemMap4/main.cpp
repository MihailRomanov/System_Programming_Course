#include <cstdio>
#include <Windows.h>

void step(int i, const char *comment)
{
    printf("Step %d : %s\n", i, comment);

    char b;
    scanf_s("%c", &b, 1);
}


int main()
{
    step(0, "Before reserv");

    void * a = VirtualAlloc(0, 1000000, MEM_RESERVE, PAGE_READWRITE);
    printf("%X\n", a);

    step(1, "Before commit");

    VirtualAlloc(a, 1000000, MEM_COMMIT, PAGE_READWRITE);

    step(2, "Before decommit");

    VirtualFree(a, 1000000, MEM_DECOMMIT);

    step(3, "Before release");

    VirtualFree(a, 0, MEM_RELEASE);

    step(4, "After free");
}