#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int size, int key) {
  int low = 0, high = size - 1, mid = (low + high) / 2;

  while ((low <= high) && (arr[mid] != key)) {
    if (key < arr[mid])
      high = mid - 1;
    else
      low = mid + 1;

    mid = (low + high) / 2;
  }
  if (low > high)
    return -1;
  else
    return mid;
}

int main(void) {

  int arr[] = {3, 4, 56, 100, 250};
  printf("Index is at : %d \n", binarySearch(arr, 5, 250));
  return EXIT_SUCCESS;
}
