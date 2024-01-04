#include <stdio.h>
#include <stdlib.h>

int sum_digits(int n) {
  // convert number to integer array
  if ((n / 10) == 0) {
    return n;
  }

  return sum_digits(n / 10) + (n % 10);
}

int main(void) {
  printf("%d \n", sum_digits(970517));
  return EXIT_SUCCESS;
}
