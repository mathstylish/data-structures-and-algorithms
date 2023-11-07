#include <stdio.h>

#include "hashtable.h"

// creates a new hash table
int main(void) {
  struct hash *hash = malloc(sizeof(struct hash));

  put(hash, "hello", "world");
  put(hash, "spring", "framework");

  remove_f(hash, "spring");

  printf("%s\n", get(hash, "hello"));
  printf("%s\n", get(hash, "spring"));

  return EXIT_SUCCESS;
}
