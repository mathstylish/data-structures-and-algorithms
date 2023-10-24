#include "queue.h"

void enqueue(struct queue *queue, int item) {
  if (is_full(queue)) {
    printf("Queue is full\n");
    return;
  }
  if (is_empty(queue)) {
    queue->front = 0;
  }
  queue->rear++;
  queue->data[queue->rear] = item;
}

int dequeue(struct queue *queue) {
  if (is_empty(queue)) {
    printf("Queue is already empty\n");
    return -1;
  }
  int dequeued = queue->data[queue->front];
  if (queue->front == queue->rear) {
    queue->front = -1;
    queue->rear = -1;
  } else {
    queue->front++;
  }
  return dequeued;
}

bool is_full(struct queue *queue) { return queue->rear == Q_LENGTH - 1; }

bool is_empty(struct queue *queue) { return queue->front == -1; }

int peek(struct queue *queue) {
  if (is_empty(queue)) {
    printf("Queue is already empty\n");
    return -1;
  }
  return queue->data[queue->front];
}

void print(struct queue *queue) {
  if (is_empty(queue)) {
    printf("Queue is empty\n");
    return;
  }
  for (int i = queue->front; i <= queue->rear; i++) {
    printf("%d ", queue->data[i]);
  }
  printf("\n");
}
