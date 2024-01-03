#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * Find the index of the largest element among list[0..last].
 *
 * @param[in] last The last element to search.
 * @param[in] list Input list
 * @return The index of the max element among list[0..last].
 *         Breaking ties by choosing the smaller index.
 * @pre list is not NULL and list[0] .. list[last] are valid.
 */
size_t max(size_t last, const long list[])
{
    long max_so_far = list[0];
    size_t max_index = 0;
    for (size_t i = 1; i <= last; i += 1)
    {
        if (list[i] > max_so_far)
        {
            max_so_far = list[i];
            max_index = i;
        }
    }
    return max_index;
}

/**
 * Sort a list using selection sort.
 *
 * @param[in] n The size of the list to sort.
 * @param[in] list The input list
 * @pre list is not NULL and list[0]..list[n-1] are valid
 * @post The list is sorted.
 */
void selection_sort(size_t n, long list[])
{
    for (size_t j = n - 1; j >= 1; j -= 1)
    {
        size_t max_pos = max(j, list);
        swap(list, max_pos, j);
    }
}
int main(int argc, char const *argv[])
{

    return 0;
}
