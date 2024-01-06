#include <stdio.h>
#include <stdlib.h>
#include "/home/shankar/Shiva/cs1010/include/cs1010.h"

void counter(void)
{
    static int count = 1; // This is initialized one time

    printf("This has been called %d time(s)\n", count);

    count++;
}

void foo(double *ptr, double trouble)
{
    ptr = &trouble;
    *ptr = 10.0;
}

int main()
{
    double *ptr;
    double x = -3.0;
    double y = 7.0;
    ptr = &y;

    foo(ptr, x);

    cs1010_println_double(x);
    cs1010_println_double(y);

    counter();
    counter();
    counter();
    counter();

    return 0;
}