#include "hashtable.h"

int main(void) {
  ch_hash *htable = ch_hash_new(ch_key_ops_string, ch_val_ops_string);

  ch_hash_put(htable, "Paris", "France");
  ch_hash_put(htable, "Berlin", "Germany");
  ch_hash_put(htable, "Warsaw", "Poland");
  ch_hash_put(htable, "Bucharest", "Romania");
  ch_hash_put(htable, "Athens", "Greece");

  printf("%s\n", (char *)ch_hash_get(htable, "Athens"));
  printf("%s\n", (char *)ch_hash_get(htable, "Bucharest"));

  ch_hash_print(htable, ch_string_print, ch_string_print);

  return 0;
}
