#include "/home/shankar/Shiva/cs1010/include/common.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {

  // Implement enhanced bubble sort

  int array[] = {17, 23, 5, 90, 12, 44, 38, 84, 77};
  const int length = LEN(array);

  for (int j = 0; j < length; j += 1) {
    for (int i = 0; i < length - 1 - j; i += 1) {
      if (array[i] > array[i + 1]) {
        // swap
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }

  // print array
  for (int i = 0; i < length; i += 1)
    printf("%d \n", array[i]);

  return 0;
}
