#include <stdio.h>

#include "stack.h"

int main(void) {
  struct node *top = NULL;

  push(&top, 2);
  push(&top, 8);
  push(&top, 12);
  push(&top, 5);
  push(&top, 7);
  push(&top, 1);

  print(top);

  int data_top = peek(top);
  printf("top: %d\n", data_top);

  int popped = pop(&top);
  printf("popped: %d\n", popped);

  return 0;
}
