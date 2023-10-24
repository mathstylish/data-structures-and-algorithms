#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void push(struct node **top, int data);
int pop(struct node **top);
bool is_empty(struct node *top);
int peek(struct node *top);
void print(struct node *top);
