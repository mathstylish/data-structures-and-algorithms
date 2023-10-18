#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5

struct stack {
  int top;
  int data_arr[CAPACITY];
};

void push(struct stack *stack, int data);
int pop(struct stack *stack);
int peek(struct stack *stack);
void print(struct stack stack);
