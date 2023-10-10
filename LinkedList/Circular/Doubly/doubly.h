#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int key;
  char *value;
} Data;


struct node {
  Data data;
  struct node *prev;
  struct node *next;
};

int size(struct node *tail);
void traverse(struct node *tail);
struct node *linear_search(struct node *tail, int key);
void add_at_beginning(struct node **tail, Data data);
void add_at_end(struct node **tail, Data data);
void add_after_position(struct node **tail, Data data, int position);
void delete_first(struct node **tail);
void delete_last(struct node **tail);
void delete_at_position(struct node **tail, int position);
void delete_by_data_key(struct node **tail, int key);