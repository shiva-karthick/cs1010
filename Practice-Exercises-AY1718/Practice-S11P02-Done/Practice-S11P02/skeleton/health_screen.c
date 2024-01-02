// health_screen.c
#include <stdio.h>

const int MAX_READINGS = 50;

typedef struct {
  float score; // the health score
  int freq;    // how many people with that score
  int occurrence;
} reading_t;

void printReadings(reading_t[], int);

int main(void) {
  reading_t readings[MAX_READINGS];
  int size = 0;

  printf("Enter score and frequency (end with 0 0):\n");

  // printReadings(readings, size); // for checking
  char buffer[1000];

  float value;
  int quantity;
  int readingsCount = 0;

  while (readingsCount < MAX_READINGS) {
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
      sscanf(buffer, "%f %d", &value, &quantity);
    }

    // Check for the termination condition "0 0"
    if (value == 0 && quantity == 0) {
      break;
    }

    // Process the input (you can perform your desired operations here)
    printf("Read: %.4f units, Quantity: %d\n", value, quantity);

    readings[readingsCount].score = value;
    readings[readingsCount].freq = quantity;
    readings[readingsCount].occurrence = 1;

    // Increment the count of readings
    readingsCount += 1;
  }

  for (int i = 0; i < readingsCount; i += 1) {
    for (int j = 0; j < readingsCount; j += 1) {
      if (i != j && readings[i].score == readings[j].score) {
        readings[i].occurrence += 1;
      }
    }
  }

  for (int i = 0; i < readingsCount; i += 1) {
    printf("%f %d %d\n", readings[i].score, readings[i].freq,
           readings[i].occurrence);
  }

  int count = 0;
  for (int i = 0; i < readingsCount; i += 1) {
    if (readings[i].occurrence == 1) {
      count += 1;
    }
  }

  printf("the unique count is %d\n", count);

  return 0;
}

// Print array arr
void printReadings(reading_t arr[], int size) {
  int i;

  for (i = 0; i < size; i++)
    printf("%f %d %d\n", arr[i].score, arr[i].freq, arr[i].occurrence);
}
