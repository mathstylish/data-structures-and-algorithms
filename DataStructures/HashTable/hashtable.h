#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H
#define CAPACITY 100

#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char *key;
  char *value;
  struct node *next;
};

struct hash {
  struct node *list[CAPACITY];
};

void put(struct hash *hash, char *key, char *value);
uint32_t hash_code(const char *key);
char *get(struct hash *hash, char *key);
// _f because remove exists in stdio
void remove_f(struct hash *hash, char *key);

#endif
