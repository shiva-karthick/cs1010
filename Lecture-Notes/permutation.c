#include <stdio.h>
#include <stdlib.h>

#include <string.h>

void swap(char a[], size_t i, size_t j)
{
    char temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

/**
 * Fix a[0]..a[k - 1] but permute characters a[k]..a[len - 1]
 * Print out each permutation.
 *
 * @param[in,out] a The array to permute
 * @param[in]     n The size of the array
 * @param[in]     k The starting index at which we will permute
 *
 * @post The string a remains unchanged
 */
void permute(char a[], size_t n, size_t k)
{
    if (k == n - 1)
    {
        printf("%s\n", a);
        return;
    }
    for (size_t i = k; i < n; i += 1)
    {
        swap(a, k, i);
        permute(a, n, k + 1);
        swap(a, i, k);
    }
}

int main()
{
    char str[] = "abc";
    permute(str, strlen(str), 0);
    // free(str);
}