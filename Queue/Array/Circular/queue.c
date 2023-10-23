#include "queue.h"

void enqueue(struct queue *queue, int data) {
  if (isFull(queue)) {
    printf("Queue is full\n");
    exit(EXIT_FAILURE);
  }
  if (isEmpty(queue)) {
    queue->front = 0;
    queue->rear = 0;
  }
  /*
   * Initially, FRONT = 0 and REAR = 0. (for Q_LENGTH = 5)
   * Enqueue element 10: FRONT = 0, REAR = (REAR + 1) % 5 = (0 + 1) % 5 = 1.
   * Enqueue element 20: FRONT = 0, REAR = (REAR + 1) % 5 = (1 + 1) % 5 = 2.
   * Enqueue element 30: FRONT = 0, REAR = (REAR + 1) % 5 = (2 + 1) % 5 = 3.
   * Enqueue element 40: FRONT = 0, REAR = (REAR + 1) % 5 = (3 + 1) % 5 = 4.
   * Enqueues element 50: FRONT = 0, REAR = (REAR + 1) % 5 = (4 + 1) % 5 = 0
   * (due to circular nature).
   * */
  queue->rear = (queue->rear++) % Q_LENGTH;
  queue->data_arr[queue->rear] = data;
}

int dequeue(struct queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    exit(EXIT_FAILURE);
  }
  int dequeued = queue->data_arr[queue->front];
  if (queue->rear == queue->front) {
    queue->front = -1;
    queue->rear = -1;
  } else {
    queue->front = (queue->front++) % Q_LENGTH;
  }
  return dequeued;
}

bool isFull(struct queue *queue) {
  return (queue->rear - queue->front == Q_LENGTH - 1) ||
         // this 2nd case is when rear is one step behind front
         (queue->front - queue->rear == 1);
}

bool isEmpty(struct queue *queue) { return queue->front == -1; }

int peek(struct queue *queue) { return queue->data_arr[queue->front]; }

void print(struct queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    exit(EXIT_FAILURE);
  }
  for (int i = queue->front; i <= queue->rear; i++) {
    printf("%d ", queue->data_arr[i]);
  }
  printf("\n");
}
