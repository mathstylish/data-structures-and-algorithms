#include "queue.h"

int main(void) {
  struct queue queue;
  queue.front = -1;
  queue.rear = -1;

  enqueue(&queue, 2);
  enqueue(&queue, -1);
  enqueue(&queue, 5);
  enqueue(&queue, 6);
  enqueue(&queue, 7);
  dequeue(&queue);
  dequeue(&queue);
  enqueue(&queue, 0);
  enqueue(&queue, 10);

  print(&queue);

  return EXIT_SUCCESS;
}
