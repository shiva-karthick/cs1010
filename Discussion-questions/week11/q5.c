#include "/home/shankar/Shiva/cs1010/include/common.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Implement insertion sort on an integer array
  int array[] = {10, 5, 7, 1, 6};
  const int length = LEN(array);

  for (int i = 0; i < length; i += 1) {
    int temp = array[i]; // store in a temp variable
    for (int j = i - 1; j >= 0; j -= 1) {
      if (temp < array[j]) {
        array[j + 1] = array[j];
      } else {
        array[j + 1] = temp;
        break;
      }
    }
    if (temp < array[0]) {
      array[0] = temp;
    }
  }

  for (int i = 0; i < length; i += 1) {
    printf("%d \n", array[i]);
  }

  return EXIT_SUCCESS;
}
