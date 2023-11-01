#include "queue.h"

void enqueue(struct queue *queue, int data) {
  if (is_full(queue)) {
    printf("Queue is full\n");
    return;
  }
  if (is_empty(queue)) {
    queue->front = 0;
    queue->rear = 0;
    queue->items[0] = data;
    return;
  }
  queue->rear = (queue->rear + 1) % Q_LENGTH;
  queue->items[queue->rear] = data;
}

int dequeue(struct queue *queue) {
  if (is_empty(queue)) {
    printf("Queue is empty\n");
    return -1;
  }
  int dequeued = queue->items[queue->front];
  if (queue->front == queue->rear) {
    queue->front = -1;
    queue->rear = -1;
  } else {
    queue->front = (queue->front + 1) % Q_LENGTH;
  }
  return dequeued;
}

bool is_full(struct queue *queue) {
  return (queue->rear + 1) % Q_LENGTH == queue->front;
}

bool is_empty(struct queue *queue) { return queue->front == -1; }

int peek(struct queue *queue) {
  if (is_empty(queue)) {
    printf("Queue is empty\n");
    return -1;
  }
  return queue->items[queue->front];
}

void print(struct queue *queue) {
  if (is_empty(queue)) {
    printf("Queue is empty\n");
    return;
  }
  int i = queue->front;
  while (i != queue->rear) {
    printf("%d ", queue->items[i]);
    i = (i + 1) % Q_LENGTH;
  }
  printf("%d ", queue->items[i]);
  printf("\n");
}
