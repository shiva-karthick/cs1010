#include <stdio.h>
#include <stdlib.h>

int largest_digit_pair(int n) {
  if (n / 100 == 0) {
    return n;
  }

  return largest_digit_pair(n / 100) > (n % 100) ? largest_digit_pair(n / 100)
                                                 : (n % 100);
}

int main(int argc, char const *argv[]) {
  int n = 5064321;
  printf("%d \n", largest_digit_pair(n));
  return 0;
}
