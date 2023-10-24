#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define Q_LENGTH 5

struct deque {
  int front;
  int rear;
  int items[Q_LENGTH];
};

void enqueue(struct deque *deque, int data);  // OK
void enqueue_front(struct deque *deque, int data);
int dequeue(struct deque *deque);
int dequeue_rear(struct deque *deque);
int peek(struct deque *deque);
bool is_empty(struct deque *deque);
bool is_full(struct deque *deque);
void print(struct deque *deque);
