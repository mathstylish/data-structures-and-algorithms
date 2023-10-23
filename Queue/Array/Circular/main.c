#include "queue.h"

int main(void) {
  struct queue queue;
  queue.front = -1;
  queue.rear = -1;

  enqueue(&queue, 1);
  enqueue(&queue, 2);
  enqueue(&queue, 3);
  enqueue(&queue, 4);

  print(&queue);

  return 0;
}
