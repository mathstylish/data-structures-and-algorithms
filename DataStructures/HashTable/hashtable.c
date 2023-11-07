#include "hashtable.h"

// MurmurHash 32-bit
static uint32_t hash_mh32(uint32_t hash) {
  hash ^= hash >> 16;
  hash *= 0x3243f6a9U;
  hash ^= hash >> 16;
  return hash;
}

uint32_t hash_code(const char *key) {
  // djb2
  uint32_t hash = (const uint32_t)5381;
  const char *str = (const char *)key;
  char c;
  while ((c = *str++)) {
    hash = ((hash << 5) + hash) + c;
  }

  return hash_mh32(hash);
}

// just a function that creates and returns a node
struct node *create_node(char *key, char *value) {
  struct node *node = malloc(sizeof(struct node));
  node->key = key;
  node->value = value;
  node->next = NULL;
  return node;
}

void put(struct hash *hash, char *key, char *value) {
  uint32_t bucket_index = hash_code(key) % CAPACITY;
  struct node *node = hash->list[bucket_index];
  if (node == NULL) {
    hash->list[bucket_index] = create_node(key, value);
  } else {
    while (node) {
      if (node->next == NULL) {
        node->next = create_node(key, value);
        return;
      }
      node = node->next;
    }
  }
}

char *get(struct hash *hash, char *key) {
  // index for array bucket, which contains a linked list, then apply linear
  // search to find node with specified key
  uint32_t bucket_index = hash_code(key) % CAPACITY;
  struct node *node = hash->list[bucket_index];
  while (node) {
    if (strcmp(node->key, key) == 0) {
      return node->value;
    }
    node = node->next;
  }
  return "NONE";
}

void remove_f(struct hash *hash, char *key) {
  uint32_t bucket_index = hash_code(key) % CAPACITY;
  struct node *node = hash->list[bucket_index];
  struct node *prev_node = NULL;
  while (node) {
    if (strcmp(node->key, key) == 0) {
      if (prev_node == NULL) {
        // if the node to be removed is the first node, update the list head.
        hash->list[bucket_index] = node->next;
      } else {
        prev_node->next = node->next;
      }
      return;
      free(node);
    }
    prev_node = node;
    node = node->next;
  }
}
