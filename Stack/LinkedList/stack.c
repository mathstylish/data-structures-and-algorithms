#include "stack.h"

void push(struct node **top, int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  if (*top == NULL) {
    *top = new_node;
    return;
  }
  new_node->next = *top;
  *top = new_node;
}

int pop(struct node **top) {
  if (*top == NULL) {
    printf("Stack underflow\n");
    exit(1);
  }
  struct node *curr = *top;
  int popped = (*top)->data;
  *top = (*top)->next;
  free(curr);
  return popped;
}

int peek(struct node *top) { return top->data; }

void print(struct node *top) {
  while (top != NULL) {
    printf("%d\n", top->data);
    top = top->next;
  }
}
