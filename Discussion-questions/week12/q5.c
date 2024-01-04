#include "/home/shankar/Shiva/cs1010/include/common.h"
#include <stdio.h>
#include <stdlib.h>

int *reverse_array(const int arr[], const int size)
{
    int *arr_parsed = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        arr_parsed[i] = arr[size - i - 1];
    }
    return arr_parsed;
}

int recursion(int array[], int size)
{
    // reverse the array using recursion
    if (size == 1)
    {
        printf("%d ", array[0]);
        return 0;
    }
    printf("%d ", array[size - 1]);
    return recursion(array, size - 1);
}

int main(int argc, char const *argv[])
{
    int n[] = {6, 3, 0, 6, 8, 1, 5};
    // int *n_parsed = reverse_array(n, 7);
    // for (int i = 0; i < 7; i++)
    // {
    // printf("%d ", n_parsed[i]);
    // }
    // free(n_parsed);

    recursion(n, 7);
    return 0;
}
