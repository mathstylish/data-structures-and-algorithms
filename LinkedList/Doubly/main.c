#include "doubly.h"

int main(void)
{
    // you don't need to allocate memory for this structure
    struct node *head = NULL;

    // use this to test
    Data first_data = {1, "John"};
    Data second_data = {2, "Zoro"};
    Data third_data = {3, "Matheus"};
    Data fourth_data = {4, "Jamila"};
    Data fifth_data = {5, "Luffy"};

    // struct node **: pointer to head address pointer
    // struct node *: pointer to the first node the head is pointing at

    // for "struct node **", use the address of *head (&head)
    // example: add_at_end(&head, first_data);

    // for "struct node *" pass the *head pointer
    // example: size(head);
    // example2: struct node *search = linear_search(head, 2);

    // compile with "gcc -o test LinkedList/Doubly/doubly.c LinkedList/Doubly/main.c"
    // run with ./test

    add_at_end(&head, fifth_data);
    add_at_end(&head, first_data);
    add_at_end(&head, second_data);
    add_at_end(&head, third_data);

    add_after_position(&head, fourth_data, 1);

    traverse(head);

    return 0;
}