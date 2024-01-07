#include <stdio.h>
void unknown(int[], int, int);
void printArray(int[], int);

int isPrime(int number)
{
    int i;
    for (i = 2; i < number; i++)
    {
        if (number % i == 0)
            return 0;
    }
    return 1;
}

int getPrime(int index)
{
    int i, count = 0;
    for (i = 2; i < 100; i++)
    {
        if (isPrime(i))
        {
            count++;
            if (count == index)
                return i;
        }
    }
}

int countPrimesRec(int number, int index, int count)
{
    int prime;
    if (number == 1)
        return count;
    prime = getPrime(index);
    if (number % prime)
    {
        return countPrimesRec(number, index + 1, count);
    }
    else
    {
        return countPrimesRec(number / prime, index, count + 1);
    }
}

int main(void)
{
    // int list[5] = {2, 0, 1, 4, 3}, i;
    // for (i = 1; i < 5; i++)
    //     unknown(list, list[0], list[i]);
    // printArray(list, 5);

    printf("%d \n", countPrimesRec(60, 1, 0));

    return 0;
}
void unknown(int arr[], int a, int b)
{
    int temp = arr[b];
    arr[b] = arr[a];
    arr[a] = temp;
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}