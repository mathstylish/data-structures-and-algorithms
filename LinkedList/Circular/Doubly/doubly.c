#include "doubly.h"

int size(struct node *tail) {
  int count = 0;
  struct node *curr = tail->next;
  do {
    count++;
    curr = curr->next;
  } while (curr != tail->next);
  return count;
}

void traverse(struct node *tail) {
  struct node *curr = tail->next;
  do {
    printf("(%d: %s) -> ", curr->data.key, curr->data.value);
    curr = curr->next;
  } while (curr != tail->next);
}

struct node *linear_search(struct node *tail, int key) {
  struct node *curr = tail->next;
  do {
    if (curr->data.key == key) return curr;
    curr = curr->next;
  } while (curr != tail->next);
  return NULL;
}

void add_at_beginning(struct node **tail, Data data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  if (*tail == NULL) {
    *tail = new_node;
    new_node->next = new_node;
    new_node->prev = new_node;
    return;
  }
  new_node->next = (*tail)->next;
  (*tail)->next->prev = new_node;
  (*tail)->next = new_node;
  new_node->prev = *tail;
}

void add_at_end(struct node **tail, Data data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  if (*tail == NULL) {
    *tail = new_node;
    new_node->next = new_node;
    new_node->prev = new_node;
    return;
  }
  (*tail)->next->prev = new_node;
  new_node->next = (*tail)->next;
  new_node->prev = *tail;
  (*tail)->next = new_node;
  *tail = (*tail)->next;
}

void add_after_position(struct node **tail, Data data, int position) {
  if (position < 1 || position > size(*tail)) {
    printf(
        "Invalid position. Position must be from 1 to current nodes in the "
        "list.\n");
    return;
  }
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  struct node *curr = (*tail)->next;
  while (position > 1) {
    curr = curr->next;
    position--;
  }
  // end of the list
  if (curr->next == (*tail)->next) {
    (*tail)->next->prev = new_node;
    new_node->next = (*tail)->next;
    new_node->prev = *tail;
    (*tail)->next = new_node;
    *tail = (*tail)->next;
    return;
  }
  // in some position, between the nodes
  new_node->next = curr->next;
  curr->next->prev = new_node;
  curr->next = new_node;
  new_node->prev = curr;
}

void delete_first(struct node **tail) {
  if (*tail == NULL) {
    printf("Linked List is Empty\n");
  }
  struct node *curr = (*tail)->next;
  (*tail)->next = (*tail)->next->next;
  (*tail)->next->prev = *tail;
  free(curr);
}

void delete_last(struct node **tail) {
  if (*tail == NULL) {
    printf("Linked List is Empty\n");
  }
  struct node *curr = *tail;
  (*tail)->prev->next = (*tail)->next;
  (*tail)->next->prev = (*tail)->prev;
  *tail = (*tail)->prev;
  free(curr);
}

void delete_at_position(struct node **tail, int position) {
  if (position < 1 || position > size(*tail)) {
    printf(
        "Invalid position. Position must be from 1 to current nodes in the "
        "list.\n");
    return;
  }
  if (*tail == NULL) {
    printf("Linked List is empty\n");
    return;
  }
  struct node *curr = (*tail)->next;
  if (position == 1) {
    (*tail)->next = (*tail)->next->next;
    (*tail)->next->prev = *tail;
    free(curr);
    return;
  }
  while (position > 1) {
    curr = curr->next;
    position--;
  }
  curr->prev->next = curr->next;
  curr->next->prev = curr->prev;
  if (curr->next == (*tail)->next) {
    curr->prev->next = (*tail)->next;
    (*tail)->next->prev = curr->prev;
    *tail = curr->prev;
  }
  free(curr);
}

void delete_by_data_key(struct node **tail, int key) {
  if (*tail == NULL) {
    printf("Linked List is empty\n");
    return;
  }
  struct node *curr = (*tail)->next;
  if ((*tail)->next->data.key == key) {
    (*tail)->next = (*tail)->next->next;
    (*tail)->next->next->prev = curr->prev;
    free(curr);
    return;
  }
  do {
    if (curr->data.key == key) {
      curr->prev->next = curr->next;
      if (curr->next == (*tail)->next) {
        curr->prev->next = (*tail)->next;
        *tail = curr->prev;
      }
      free(curr);
      return;
    }
    curr->prev = curr;
    curr = curr->next;
  } while (curr != (*tail)->next);
}
