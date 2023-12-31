#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define Q_LENGTH 5

struct queue {
  int front;
  int rear;
  int data[Q_LENGTH];
};

void enqueue(struct queue *queue, int item);
int dequeue(struct queue *queue);
bool isFull(struct queue *queue);
bool isEmpty(struct queue *queue);
int peek(struct queue *queue);
void print(struct queue *queue);
