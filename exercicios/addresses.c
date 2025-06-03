#include <stdio.h>

int main(void)
{

    int a = 5;
    int b = 10;
    int *p1 = &a;
    int *p2 = &b;

    printf("Address of a: %p\n", (void*)&a);
    printf("Address of b: %p\n", (void*)&b);
    printf("Value of p1: %p\n", (void*)p1);
    printf("Value of p2: %p\n", (void*)p2);

    return 0;
}