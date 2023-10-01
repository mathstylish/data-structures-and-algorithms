#include "singly.h"

int size(struct node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

struct node *linear_search(struct node *head, int key)
{
    while (head != NULL)
    {
        if (head->data.key == key) return head;
        head = head->next;
    }
    return NULL;
}

void traverse(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    while (head != NULL)
    {
        printf("(%d: %s) -> ", head->data.key, head->data.value);
        head = head->next;
    }
    printf("NULL\n");
}

void add_at_end(struct node **head, Data data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    struct node *curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new_node;
}

void add_at_beginning(struct node **head, Data data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    struct node *prev_head = *head;
    *head = new_node;
    new_node->next = prev_head;
}

void add_after_position(struct node **head, Data data, int position)
{
    if (position < 1 || position > size(*head))
    {
        printf("Invalid position. Position must be from 1 to current nodes in the list.\n");
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *curr = NULL;
    new_node->data = data;
    new_node->next = NULL;
    if (position == 1)
    {
        curr = *head;
        *head = new_node;
        new_node->next = curr;
        return;
    }
    curr = *head;
    while (position > 1)
    {
        curr = curr->next;
        position--;
    }
    new_node->next = curr->next;
    curr->next = new_node;
}

void delete_first(struct node **head)
{
    if (*head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    struct node *curr = *head;
    *head = curr->next;
    free(curr);
}

void delete_last(struct node **head)
{
    if (*head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(head);
        return;
    }
    struct node *curr = *head;
    while (curr->next->next != NULL) curr = curr->next;
    free(curr->next);
    curr->next = NULL;
}

void delete_at_position(struct node **head, int position)
{
     if (position < 1 || position > size(*head))
    {
        printf("Invalid position. Position must be from 1 to current nodes in the list.\n");
        return;
    }
    if (*head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    struct node *curr = *head;
    if (position == 1)
    {
        *head = curr->next;
        free(curr);
        return;
    }
    struct node *prev = NULL;
    while (position > 1)
    {
        prev = curr;
        curr = curr->next;
        position--;
    }
    prev->next = curr->next;
    free(curr);
}

void delete_by_data_key(struct node **head, int key)
{
    if (*head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    struct node *curr = *head;
    if ((*head)->data.key == key)
    {
        *head = (*head)->next;
        free(curr);
        return;
    }
    struct node *prev = NULL;
    while (curr != NULL)
    {
        if (curr->data.key == key)
        {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void clear_list(struct node **head)
{
    if (*head == NULL)
    {
        printf("Linked List is already empty\n");
        return;
    }
    struct node *curr = *head;
    while (curr != NULL)
    {
        curr = curr->next;
        free(*head);
        *head = curr;
    }
}

void reverse(struct node **head)
{
    if (*head == NULL)
    {
        printf("Linked List is empty\n");
        return; 
    }
    struct node *prev = NULL;
    struct node *next = NULL;
    while (*head != NULL)
    {
        // store the next node
        next = (*head)->next;
        // reverse the link
        (*head)->next = prev;
        // move prev and *head node one step forward
        prev = *head;
        *head = next;
    }
    // update the head to point to the last node
    *head = prev;
}