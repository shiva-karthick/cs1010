#include "/home/shankar/Shiva/cs1010/include/common.h"
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char const *argv[])
{
    // Selection sort
    int array[] = {12345, 9870, 32, 5555555, 801784, 729};

    const int len = LEN(array);
    int arr[len];

    for (int i = 0; i < len; i += 1)
    {
        int count = 0;
        int temp = array[i];
        while (temp > 0)
        {
            temp /= 10;
            count += 1;
        }

        if (count < 3)
        {
            arr[i] = array[i];
            continue;
        }
        else
        {
            arr[i] = array[i] / pow(10, count - 3);
        }
    }

    // print array
    for (int i = 0; i < len; i += 1)
    {
        printf("%d \n", arr[i]);
    }

    const int length = LEN(arr);

    for (int i = 0; i < length - 1; i += 1)
    {
        int min = i;
        for (int j = i + 1; j < length; j += 1)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        if (i == min)
        {
            continue;
        }
        else
        {
            swap(&arr[i], &arr[min]);
        }
    }

    printf("\n After sorting \n");
    // print the array
    for (int i = 0; i < length; i += 1)
    {
        printf("%d \n", arr[i]);
    }

    /**
     * Note the program is not quite yet done. We need to compare the first 3 digits of the numbers with the sorted array, then print the array. I didn't implement this part because I'm lazy.
     */

    return 0;
}
