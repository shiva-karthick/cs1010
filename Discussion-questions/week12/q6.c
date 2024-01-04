#include <stdio.h>
#include <stdlib.h>

// North-East paths
int ne(int n, int e)
{
    // Base case
    if (n == 0 || e == 0)
    {
        return 1;
    }
    // Recursive case
    return ne(n - 1, e) + ne(n, e - 1);
}

int main(int argc, char const *argv[])
{
    printf("%d \n", ne(0, 2)); // answer is 1
    printf("%d \n", ne(1, 3)); // answer is 4
    printf("%d \n", ne(3, 2)); // answer is 10
    return 0;
}
