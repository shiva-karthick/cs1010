#include "/home/shankar/Shiva/cs1010/include/common.h"
#include "/home/shankar/Shiva/cs1010/include/cs1010.h"
#include <stdio.h>

#define PI 3.14159

struct point_t
{
  int x;
  int y;
};

int main(int argc, char *argv[])
{
  char line[50];
  int n;

  // get the size of the array of structs
  if (fgets(line, sizeof(line), stdin) != NULL)
  {
    sscanf(line, "%d", &n);
  }

  struct point_t array[n];

  for (int i = 0; i < n; i += 1)
  {
    fgets(line, sizeof(line), stdin);
    int x, y;

    // Use sscanf to parse each line
    if (sscanf(line, "%d %d", &x, &y) == 2)
    {
      printf("Read values: %d, %d \n", x, y);
      array[i].x = x;
      array[i].y = y;
    }
  }

  double radius = 0.0;
  double temp = sqrt(pow(array[0].x, 2) + pow(array[0].y, 2));
  for (int i = 1; i < n; i += 1)
  {
    radius = sqrt(pow(array[i].x, 2) + pow(array[i].y, 2));
    if (radius > temp)
    {
      temp = radius;
    }
  }

  printf("area of smallest circle is %f \n", PI * temp * temp);

  for (int i = 0; i < n; i += 1)
  {
    printf("array[%d]: x = %d, y = %d \n", i, array[i].x, array[i].y);
  }

  return EXIT_SUCCESS;
}
