#include "stack.h"

void push(struct stack *stack, int data) {
  if (isFull(stack)) {
    printf("Stack overflow\n");
    return;
  }
  stack->top++;
  stack->items[stack->top] = data;
}
int pop(struct stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack underflow\n");
    return -1;
  }
  int popped = stack->items[stack->top];
  stack->top--;
  return popped;
}

bool isEmpty(struct stack *stack) { return stack->top == -1; }

bool isFull(struct stack *stack) { return stack->top == CAPACITY - 1; }

int peek(struct stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack undeflow\n");
    return -1;
  }
  return stack->items[stack->top];
}

void print(struct stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack underflow\n");
    return;
  }
  for (int i = stack->top; i > -1; i--) printf("%d\n", stack->items[i]);
}
