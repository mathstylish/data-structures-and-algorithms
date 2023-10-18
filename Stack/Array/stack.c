#include "stack.h"

void push(struct stack *stack, int data) {
  if (stack->top == CAPACITY - 1) {
    printf("Stack overflow\n");
    return;
  }
  stack->top++;
  stack->data_arr[stack->top] = data;
}
int pop(struct stack *stack) {
  if (stack->top == -1) {
    printf("Stack underflow\n");
    exit(1);
  }
  int popped = stack->data_arr[stack->top];
  stack->top--;
  return popped;
}

int peek(struct stack *stack) {
  if (stack->top == -1) {
    printf("Stack undeflow\n");
    exit(1);
  }
  return stack->data_arr[stack->top];
}

void print(struct stack stack) {
  if (stack.top == -1) {
    printf("Stack underflow\n");
    return;
  }
  for (int i = stack.top; i > -1; i--) printf("%d\n", stack.data_arr[i]);
}
