#include <cstdio>
#include <stdlib.h>

void step(int i, const char *comment)
{
    printf("Step %d : %s\n", i, comment);

    char b;
    scanf_s("%c", &b, 1);
}




int main()
{
    step(0, "Before malloc");

    int * a = (int *) malloc(10000);

    step(1, "After malloc / before free");

    free(a);

    step(2, "After free");
}