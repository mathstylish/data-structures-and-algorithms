#include "queue.h"

void enqueue(struct queue *queue, int data) {
  if (isFull(queue)) {
    printf("Queue is full\n");
    return;
  }
  if (isEmpty(queue)) {
    queue->front = 0;
  }
  queue->rear = (queue->rear + 1) % Q_LENGTH;
  queue->items[queue->rear] = data;
}

int dequeue(struct queue *queue) {
  if (isEmpty(queue)) {
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

bool isFull(struct queue *queue) {
  return (queue->front == queue->rear + 1) ||
         (queue->front == 0 && queue->rear == Q_LENGTH - 1);
}

bool isEmpty(struct queue *queue) { return queue->front == -1; }

int peek(struct queue *queue) { return queue->items[queue->front]; }

void print(struct queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    return;
  }
  int i = 0;
  while (queue->front != queue->rear) {
    printf("%d ", queue->items[i]);
    i = (i + 1) % Q_LENGTH;
  }
}
