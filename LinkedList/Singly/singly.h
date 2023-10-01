#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int key;
    char *value;
} Data;

struct node
{
    Data data;
    struct node *next;
};

int size(struct node *head);
struct node *linear_search(struct node *head, int key);
void traverse(struct node *head);
void add_at_end(struct node **head, Data data);
void add_at_beginning(struct node **head, Data data);
void add_after_position(struct node **head, Data data, int position);
void delete_first(struct node **head);
void delete_last(struct node **head);
void reverse(struct node **head);