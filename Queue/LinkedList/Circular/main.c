#include "queue.h"

int main(void) {
  struct queue *queue = malloc(sizeof(struct queue));
  queue->front = NULL;
  queue->rear = NULL;

  enqueue(&queue, 2);
  enqueue(&queue, 7);
  enqueue(&queue, 1);
  enqueue(&queue, 8);
  enqueue(&queue, 9);

  dequeue(&queue);
  dequeue(&queue);

  print(queue);  // 1 8 9

  printf("%d points to %d\n", queue->rear->data,
         queue->rear->next->data);  // 9 points to 1

  return EXIT_SUCCESS;
}
