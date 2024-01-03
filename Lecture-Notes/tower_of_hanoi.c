#include <stdio.h>
#include <stdlib.h>

void tower(char, char, char, int);

int main(int argc, char const *argv[]) {
  int disks;
  printf("Enter number of disks: ");
  scanf("%d", &disks);
  tower('A', 'B', 'C', disks);

  return 0;
}

void tower(char source, char temp, char dest, int n) {
  if (n > 0) {
    tower(source, dest, temp, n - 1); // Move n - 1 disks from the source peg to
                                      // the temp peg using the destination peg
    printf("Move disk %d from %c to %c\n", n, source,
           dest); // this is like the inflexion point, where the last disk is
                  // moved from source to destination, and the rest of the disks
                  // are moved from temp to destination
    tower(temp, source, dest, n - 1);
  }
}
