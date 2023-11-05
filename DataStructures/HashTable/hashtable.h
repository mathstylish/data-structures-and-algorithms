#define CH_HASH_CAPACITY_INIT (32)
#define CH_HASH_CAPACITY_MULT (2)
#define CH_HASH_GROWTH (1)

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// credits to
// https://www.andreinc.net/2021/10/02/implementing-hash-tables-in-c-part-1

// simple structures used to group functions specific to the data inserted int
// the hash table. It's impossible to think of all the possible combinations of
// keys/pairs and their types, so we let the user supply us with the truth
// how we can pass functions around "Pointers":
// https://en.wikipedia.org/wiki/Function_pointer
typedef struct ch_key_ops_s {
  uint32_t (*hash)(
      const void *data,
      void *arg);  // is not the actual bucket index, but it’s the hash of the
                   // data that is going inside the hash table. This is only
                   // computed once, and it’s (re)used whenever we need to **
                   // rehash** our table
  void *(*cp)(const void *data, void *arg);
  void (*free)(void *data, void *arg);
  bool (*eq)(const void *data1, const void *data2, void *arg);
  void *arg;
} ch_key_ops;

typedef struct ch_val_ops_s {
  void *(*cp)(const void *data, void *arg);
  void (*free)(void *data, void *arg);
  bool (*eq)(const void *data1, const void *data2, void *arg);
  void *arg;
} ch_val_ops;

// the buckets are composed of linked lists: **
typedef struct ch_node_s {
  uint32_t hash;  // not the actual bucket index, but it's hash of data inside
                  // the hash table
  void *key;
  void *val;
  struct ch_node_s *next;
} ch_node;

// chained hash struct
typedef struct ch_hash_s {
  size_t capacity;    // the total number of available buckets
  size_t size;        // the total number of elements
  ch_node **buckets;  // a dynamic (expandable if needed) array of linked lists
  // structures to keep tracking of data-specific operations (e.g., a function
  // that checks if two values are equal, etc.)
  ch_key_ops key_ops;
  ch_val_ops val_ops;
} ch_hash;

// creates a new hash table
ch_hash *ch_hash_new(ch_key_ops k_ops, ch_val_ops v_ops);
// free the memory associated with the hash (and all of its contents)
void ch_hash_free(ch_hash *hash);
// gets the value coresponding to a key
// if the key is not found returns NULL
void *ch_hash_get(ch_hash *hash, const void *k);
// Checks if a key exists or not in the hash table
bool ch_hash_contains(ch_hash *hash, const void *k);
// adds a <key, value> pair to the table
void ch_hash_put(ch_hash *hash, const void *key, const void *value);
// prints the contents of the hash table
void ch_hash_print(ch_hash *hash, void (*print_key)(const void *k),
                   void (*print_val)(const void *v));
// get the total number of collisions
uint32_t ch_hash_numcol(ch_hash *hash);

// string methods
void *ch_string_cp(const void *data, void *arg);
bool ch_string_eq(const void *data1, const void *data2, void *arg);
void ch_string_free(void *data, void *arg);
void ch_string_print(const void *data);

extern ch_key_ops ch_key_ops_string;
extern ch_val_ops ch_val_ops_string;
