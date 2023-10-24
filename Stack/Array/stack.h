#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5

struct stack {
  int top;
  int items[CAPACITY];
};

void push(struct stack *stack, int data);
int pop(struct stack *stack);
bool is_empty(struct stack *stack);
bool is_full(struct stack *stack);
int peek(struct stack *stack);
void print(struct stack *stack);
