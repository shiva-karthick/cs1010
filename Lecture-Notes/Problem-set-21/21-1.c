#include <stdio.h>
#include <stdlib.h>

int binarySearch(int list[], int size, int key) {
  int low = 0, high = size - 1, mid = (low + high) / 2;

  while ((low <= high) && list[mid] != key) {
    if (key < list[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }

    mid = (low + high) / 2;
  }
  if (low > high) {
    return -1;
  } else {
    return mid;
  }
}

int main(int argc, char const *argv[]) {
  // rewrite the binary search function using a for loop
  int arr[] = {3, 4, 56, 100, 250};
  printf("Index is at : %d \n", binarySearch(arr, 5, 250));
  return 0;
}
