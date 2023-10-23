#include "queue.h"

int main(void) {
  struct queue queue;
  queue.front = -1;
  queue.rear = -1;

  enqueue(&queue, 1);
  enqueue(&queue, 2);
  enqueue(&queue, 3);
  enqueue(&queue, 4);
  enqueue(&queue, 7);

  dequeue(&queue);

  enqueue(&queue, 15);

  dequeue(&queue);

  enqueue(&queue, 20);

  printf("%d ", queue.items[0]);
  printf("%d ", queue.items[1]);
  printf("%d ", queue.items[2]);
  printf("%d ", queue.items[3]);
  printf("%d\n", queue.items[4]);

  return EXIT_SUCCESS;
}
