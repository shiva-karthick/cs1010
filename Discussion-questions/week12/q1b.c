#include <stdio.h>
#include <stdlib.h>

// Define a structure for stack elements
struct Stack {
  int value;
  int state;
};

// Iterative version of the function
int q_iterative(int n) {
  // Create a stack to simulate the recursive calls
  struct Stack stack[100]; // Adjust the size based on your needs
  int stackSize = 0;       // Stack size to keep track of elements in the stack
  int result = 0;

  // Push the initial call to the stack
  stack[stackSize++] = (struct Stack){n, 0};

  while (stackSize > 0) {
    struct Stack current = stack[stackSize - 1];
    stackSize -= 1;

    int value = current.value;
    int state = current.state;

    if (state == 0) {
      // First recursive call q(n-3)
      if (value < 3) {
        result += value + 1;
      } else {
        stack[stackSize++] = (struct Stack){value, 1};     // Save state
        stack[stackSize++] = (struct Stack){value - 3, 0}; // Recursive call
      }
    } else if (state == 1) {
      // Second recursive call q(q-1)
      stack[stackSize++] = (struct Stack){value, 2};     // Save state
      stack[stackSize++] = (struct Stack){value - 1, 0}; // Recursive call
    } else if (state == 2) {
      // Add the results of the two recursive calls
      result += stack[--stackSize].value;
    }
  }

  return result;
}

int main(int argc, char const *argv[]) {
  int result = q_iterative(3);
  printf("Result: %d\n", result);
  return 0;
}
