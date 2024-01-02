#include "/home/shankar/Shiva/cs1010/include/common.h"
#include "/home/shankar/Shiva/cs1010/include/cs1010.h"

struct interval_t {
  int start;
  int finish;
};

int main(int argc, char const *argv[]) {
  char buffer[50];

  int n_lessons;
  if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
    sscanf(buffer, "%d", &n_lessons);
  }

  struct interval_t array[n_lessons];

  for (int i = 0; i < n_lessons; i += 1) {
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
      sscanf(buffer, "%d %d", &array[i].start, &array[i].finish);
    }
  }

  for (int i = 0; i < n_lessons; i += 1) {
    printf("array[i].x = %d, array[i].y = %d \n", array[i].start,
           array[i].finish);
  }

  int timeline[1000] = {0};
  // Find the minimum and maximum values
  for (int i = 0; i < n_lessons; i += 1) {
    int minimum = array[i].start, maximum = array[i].finish;
    for (int j = minimum; j < maximum; j += 1) {
      timeline[j] += 1;
    }
  }

  // Find the largest number in the array
  int largest_num = 0, start = 0, finish = 0;
  for (int i = 0; i < 1000; i += 1) {
    if (timeline[i] > largest_num) {
      largest_num = timeline[i];
    }
  }
  for (int i = 0; i < 1000; i += 1) {
    if (timeline[i] == largest_num) {
      start = i;
      break;
    }
  }
  for (int i = 1000; i >= 0; i -= 1) {
    if (timeline[i] == largest_num) {
      finish = i;
      break;
    }
  }

  printf("largest_num = %d, start = %d, finish = %d\n", largest_num, start,
         finish);

  // duration of longest lesson
  int longest_lesson = array[0].finish - array[0].start;
  for (int i = 1; i < n_lessons; i += 1) {
    int temp = array[i].finish - array[i].start;
    if (longest_lesson < temp) {
      longest_lesson = temp;
    }
  }

  printf("duration of longest lesson is %d\n", longest_lesson);

  // Find the minimum from array[i].start and the maximum from array[i].finish
  int free_periods = 0;
  int count = 0;
  int mini_finish = 0;

  for (int i = 0; i < 1000; i += 1) {
    if (timeline[i] == 0 && timeline[i + 1] != 0) {
      mini_finish = i;
      free_periods += 1;
      printf("free_periods : %d \n", free_periods - 2);
    } else if (timeline[i] == 0 && timeline[i + 1] == 0) {
      count += 1;
    }
  }
  return 0;
}
