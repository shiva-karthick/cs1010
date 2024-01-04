#include "/home/shankar/Shiva/cs1010/include/common.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {

  // Implement enhanced bubble sort

  int array[] = {12, 13, 12, 14};
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

  /*
   * I am going to skip this, since this question is just testing on string
   * manipulations. However, I want to write out how to solve. Firstly, given
   * string 1, remove the whitespaces, convert all chars to lowerspace. Perform
   * similar operation for string 2 as well. Then, convert all the characters to
   * ASCII format. Convert them into integer arrays. Sort the arrays, then make
   * sure each integer maches in both arrays.*/

  return 0;
}
