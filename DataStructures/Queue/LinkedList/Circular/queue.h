#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct queue {
  struct node *front;
  struct node *rear;
};

void enqueue(struct queue **queue, int data);
int dequeue(struct queue **queue);
int peek(struct queue *queue);
bool is_empty(struct queue *queue);
void print(struct queue *queue);
