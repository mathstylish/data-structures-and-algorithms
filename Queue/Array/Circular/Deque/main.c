#include "deque.h"

int main(void) {
  struct deque deque;
  deque.front = -1;
  deque.rear = -1;

  enqueue_front(&deque, 2);
  enqueue_front(&deque, 5);
  enqueue(&deque, -1);
  enqueue(&deque, 0);
  enqueue_front(&deque, 7);

  dequeue(&deque);
  dequeue_rear(&deque);
  dequeue(&deque);

  print(&deque);  // 2 -1

  return EXIT_SUCCESS;
}
