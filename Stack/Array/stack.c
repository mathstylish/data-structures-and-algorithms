#include "stack.h"

void push(struct stack *stack, int data) {
  if (isFull(stack)) {
    printf("Stack overflow\n");
    return;
  }
  stack->top++;
  stack->data_arr[stack->top] = data;
}
int pop(struct stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack underflow\n");
    exit(EXIT_FAILURE);
  }
  int popped = stack->data_arr[stack->top];
  stack->top--;
  return popped;
}

bool isEmpty(struct stack *stack) { return stack->top == -1; }

bool isFull(struct stack *stack) { return stack->top == CAPACITY - 1; }

int peek(struct stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack undeflow\n");
    exit(EXIT_FAILURE);
  }
  return stack->data_arr[stack->top];
}

void print(struct stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack underflow\n");
    return;
  }
  for (int i = stack->top; i > -1; i--) printf("%d\n", stack->data_arr[i]);
}
