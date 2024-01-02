#include "/home/shankar/Shiva/cs1010/include/common.h"
#include "/home/shankar/Shiva/cs1010/include/cs1010.h"

struct result_t {
  char module_code[7]; // including the null character
  char grade[3];
  unsigned int module_credits;
};

struct student_t {
  char name[30];
  struct result_t results[50];
};

struct grade_t {
  char grade[3];
  float grade_point;
};

int main(int argc, char const *argv[]) {
  char buffer[50];
  struct grade_t grades[13] = {
      {"A+", 5.0}, {"A", 5.0},  {"A-", 4.5}, {"B+", 4.0}, {"B", 3.5},
      {"B-", 3.0}, {"C+", 2.5}, {"C", 2.0},  {"D+", 1.5}, {"D", 1.0},
      {"F", 0.0},  {"S", 0.0},  {"U", 0.0},
  };

  // Read in a student's name
  if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
    struct student_t student;
    sscanf(buffer, "%[^\n]", student.name); // used for parsing the data
    printf("Student name: %s\n", student.name);

    int number_of_modules = 0;
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
      sscanf(buffer, "%d", &number_of_modules);
      printf("Number of modules: %d\n", number_of_modules);
    }

    for (int i = 0; i < number_of_modules; i += 1) {
      if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        sscanf(buffer, "%s %s %u", student.results[i].module_code,
               student.results[i].grade, &student.results[i].module_credits);
        printf("Module code: %s\n", student.results[i].module_code);
        printf("Grade: %s\n", student.results[i].grade);
        printf("Module credits: %u\n", student.results[i].module_credits);
      }
    }

    // Calculate the CAP
    float cap = 0;
    unsigned int total_credits = 0;
    for (int j = 0; j < number_of_modules; j += 1) {
      for (int k = 0; k < 13; k += 1) {
        if (strcmp(student.results[j].grade, grades[k].grade) == 0) {
          cap += student.results[j].module_credits * grades[k].grade_point;
          total_credits += student.results[j].module_credits;
        }
      }
    }
    cap /= total_credits;
    printf("CAP: %.2f\n", cap);
  }
  return 0;
}
