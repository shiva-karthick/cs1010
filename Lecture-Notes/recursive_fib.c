#include <stdio.h>

long fib(long n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main(int argc, char const *argv[])
{
    return 0;
}
