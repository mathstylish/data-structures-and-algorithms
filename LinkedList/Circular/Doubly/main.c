#include "doubly.h"

int main(void) {
  // you don't need to allocate memory for this structure
  struct node *tail = NULL;

  // use this to test
  Data first_data = {7, "John"};
  Data second_data = {1, "Zoro"};
  Data third_data = {3, "Matheus"};
  Data fourth_data = {4, "Jamila"};
  Data fifth_data = {5, "Luffy"};

  // struct node **: pointer to tail address pointer
  // struct node *: pointer to the last node the tail is pointing at

  // for "struct node **", use the address of *tail (&tail)
  // example: add_at_end(&tail, first_data);

  // for "struct node *" pass the *tail pointer
  // example: size(tail);
  // example2: struct node *search = linear_search(tail, 2);

  // compile with "gcc -o test LinkedList/Circular/Doubly/doubly.c
  // LinkedList/Circular/Doubly/main.c" run with ./test

  add_at_end(&tail, fifth_data);
  add_at_end(&tail, first_data);
  add_at_end(&tail, second_data);
  add_at_end(&tail, third_data);

  add_after_position(&tail, fourth_data, 1);

  traverse(tail);

  return 0;
}
