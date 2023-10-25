#include "queue.h"

void enqueue(struct queue **queue, int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  if (is_empty(*queue)) {
    // front and rear points to the same node
    (*queue)->front = new_node;
    (*queue)->rear = new_node;
    // points to start (due to the circular nature)
    (*queue)->rear->next = (*queue)->front;
    return;
  }
  (*queue)->rear->next = new_node;
  (*queue)->rear = new_node;
  // points to start (due to the circular nature)
  (*queue)->rear->next = (*queue)->front;
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
    // curr front next will be the new front
    (*queue)->front = (*queue)->front->next;
    // curr rear point to new front (due to the circular nature)
    (*queue)->rear->next = (*queue)->front;
  }
  free(curr);
  return dequeued;
}

int peek(struct queue *queue) { return queue->front->data; }

bool is_empty(struct queue *queue) {
  return queue->front == NULL && queue->rear == NULL;
}

void print(struct queue *queue) {
  if (is_empty(queue)) {
    printf("Queue is empty\n");
    return;
  }
  struct node *curr = queue->front;
  while (curr->next != queue->front) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("%d ", curr->data);
  printf("\n");
}
