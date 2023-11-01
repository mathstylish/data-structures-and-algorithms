#include "deque.h"

void enqueue(struct deque *deque, int data) {
  if (is_full(deque)) {
    printf("Queue is full\n");
    return;
  }
  if (is_empty(deque)) {
    deque->front = 0;
    deque->rear = 0;
    deque->items[0] = data;
    return;
  }
  // points to start if rear == Q_LENGTH-1 (due to circular nature)
  if (deque->rear == Q_LENGTH - 1)
    deque->rear = 0;
  else
    deque->rear++;
  deque->items[deque->rear] = data;
}

void enqueue_front(struct deque *deque, int data) {
  if (is_full(deque)) {
    printf("Queue is full\n");
    return;
  }
  if (is_empty(deque)) {
    deque->front = 0;
    deque->rear = 0;
    deque->items[0] = data;
    return;
  }
  // points to end if front == 0 (due to the circular nature)
  if (deque->front == 0)
    deque->front = Q_LENGTH - 1;
  else
    deque->front--;
  deque->items[deque->front] = data;
}

int dequeue(struct deque *deque) {
  if (is_empty(deque)) {
    printf("Queue is empty\n");
    return -1;
  }
  // last element
  int dequeued = deque->items[deque->rear];
  if (deque->front == deque->rear) {
    deque->front = -1;
    deque->rear = -1;
  } else if (deque->front == Q_LENGTH - 1) {
    // points to start if front == Q_LENGTH-1 (due to the circular nature)
    deque->front = 0;
  } else {
    deque->front++;
  }
  return dequeued;
}

int dequeue_rear(struct deque *deque) {
  if (is_empty(deque)) {
    printf("Queue is empty\n");
    return -1;
  }
  int dequeued = deque->items[deque->rear];
  // last element
  if (deque->front == deque->rear) {
    deque->front = -1;
    deque->rear = -1;
    // points to end if rear == 0 (due to the circular nature)
  } else if (deque->rear == 0) {
    deque->rear = Q_LENGTH - 1;
  } else {
    deque->rear--;
  }
  return dequeued;
}

int peek(struct deque *deque) {
  if (is_empty(deque)) {
    printf("Queue is empty\n");
    return -1;
  }
  return deque->items[deque->front];
}

bool is_empty(struct deque *deque) { return deque->front == -1; }

bool is_full(struct deque *deque) {
  return (deque->front == 0 && deque->rear == Q_LENGTH - 1) ||
         (deque->front == deque->rear + 1);
}

void print(struct deque *deque) {
  if (is_empty(deque)) {
    printf("Queue is empty\n");
    return;
  }
  int i = deque->front;
  while (i != deque->rear) {
    printf("%d ", deque->items[i]);
    i = (i + 1) % Q_LENGTH;
  }
  printf("%d ", deque->items[i]);
  printf("\n");
}
