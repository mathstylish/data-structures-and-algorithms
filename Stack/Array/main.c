#include "stack.h"

int main(int argc, char *argv[]) {
  struct stack stack;
  stack.top = -1;

  push(&stack, 2);
  push(&stack, 6);
  push(&stack, 13);
  push(&stack, 87);
  push(&stack, 19);

  print(&stack);

  // compile with "gcc -o test Stack/Array/stack.c Stack/Array/main.c"
  // run with ./test

  return EXIT_SUCCESS;
}
