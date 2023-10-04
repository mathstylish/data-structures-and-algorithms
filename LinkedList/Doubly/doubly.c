#include "doubly.h"

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
        if (head->data.key == key)
            return head;
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
    new_node->prev = NULL;
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    struct node *curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new_node;
    new_node->prev = curr;
}

void add_at_beginning(struct node **head, Data data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    struct node *prev_head = *head;
    *head = new_node;
    new_node->next = prev_head;
    prev_head->prev = new_node;
}

void add_after_position(struct node **head, Data data, int position)
{
    if (position < 1 || position > size(*head))
    {
        printf("Invalid position. Position must be from 1 to current nodes in the list.\n");
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    struct node *curr = *head;
    while (position > 1)
    {
        curr = curr->next;
        position--;
    }
    // end of the list
    if (curr->next == NULL)
    {
        curr->next = new_node;
        new_node->prev = curr;
        return;
    }
    // in some position, between the nodes
    new_node->next = curr->next;
    curr->next->prev = new_node;
    curr->next = new_node;
    new_node->prev = curr;
}

void delete_first(struct node **head)
{
    if (head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    struct node *curr = *head;
    *head = curr->next;
    (*head)->prev = NULL;
    free(curr);
}

void delete_last(struct node **head)
{
    if (head == NULL)
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
    while (curr->next->next != NULL)
        curr = curr->next;
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
        (*head)->prev = NULL;
        free(curr);
        return;
    }
    while (position > 1)
    {
        curr = curr->next;
        position--;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
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
    while (curr != NULL)
    {
        if (curr->data.key == key)
        {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            free(curr);
            return;
        }
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
    struct node *current = *head;
    struct node *temp = NULL;

    while (current != NULL)
    {
        // Swap the next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node
        current = current->prev;
    }

    // Update the new head
    if (temp != NULL)
    {
        *head = temp->prev;
    }
}