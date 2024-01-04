#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int arr[] = {23, 45, 12};

  int *a = &arr[0];
  int *b = &arr[2];

  // swap
  int temp = *a;
  *a = *b;
  *b = temp;

  for (int i = 0; i < 3; i += 1) {
    printf("%d \n", arr[i]);
  }

  return EXIT_SUCCESS;
}
