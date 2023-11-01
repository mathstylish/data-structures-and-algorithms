#include "queue.h"

void enqueue(struct queue **queue, int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  if (is_empty(*queue)) {
    (*queue)->front = new_node;
    (*queue)->rear = new_node;
    return;
  }
  (*queue)->rear->next = new_node;
  (*queue)->rear = new_node;
}

int dequeue(struct queue **queue) {
  if (is_empty(*queue)) {
    printf("Queue is empty\n");
    exit(EXIT_FAILURE);
  }
  int dequeued = (*queue)->front->data;
  struct node *curr = (*queue)->front;
  if ((*queue)->front == (*queue)->rear) {
    (*queue)->front = NULL;
    (*queue)->rear = NULL;
  } else {
    (*queue)->front = (*queue)->front->next;
  }
  free(curr);
  return dequeued;
}

int peek(struct queue *queue) { return queue->front->data; }

bool is_empty(struct queue *queue) {
  return queue->front == NULL && queue->rear == NULL;
}

void print(struct queue *queue) {
  while (queue->front != NULL) {
    printf("%d ", queue->front->data);
    queue->front = queue->front->next;
  }
  printf("\n");
}
